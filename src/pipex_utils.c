/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:35:45 by aaitelka          #+#    #+#             */
/*   Updated: 2024/02/24 17:35:46 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cmd_utils.h"
#include "../include/pipex_utils.h"

void	check(char *msg, int error_code)
{
	if (!error_code)
		return ;
	if (error_code == -1)
	{
		perror(msg);
		exit(1);
	}
}

t_cmd	*get_instance(char *ep[], char *file, char *r_cmd, char **opts)
{
	t_cmd	*cmd;

	cmd = (t_cmd *) malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->file = file;
	cmd->cmd = r_cmd;
	cmd->opts = opts;
	cmd->envp = ep;
	cmd->access_path = get_access_path(ep, r_cmd);
	return (cmd);
}

void	run_first(t_cmd *cmd, int pfd[])
{
	int		fd;
	pid_t	id;

	id = fork();
	check("Error when forking new process", id);
	if (id == 0)
	{
		fd = open(cmd->file, O_RDONLY | O_CREAT, 0777);
		check("Error opening infile", fd);
		check("Error duplicating infile", dup2(fd, STDIN_FILENO));
		check("Error closing infile", close(fd));
		check("Error closing f_pfd[0]", close(pfd[0]));
		check("Error duplicating f_pipe", dup2(pfd[1], STDOUT_FILENO));
		check("Error closing f_pfd[1]", close(pfd[1]));
		check("Error executing execve",
			execve(cmd->access_path, cmd->opts, cmd->envp));
	}
}

void	run_next(t_cmd *cmd, int pfd[])
{
	int		fd;
	pid_t	id;

	id = fork();
	check("Error when forking new process", id);
	if (id == 0)
	{
		fd = open(cmd->file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		check("Error opening outfile", fd);
		check("Error duplicating outfile", dup2(fd, STDOUT_FILENO));
		check("Error closing outfile", close(fd));
		check("Error closing n_pfd[1]", close(pfd[1]));
		check("Error duplicating n_pipe", dup2(pfd[0], STDIN_FILENO));
		check("Error closing n_pfd[0]", close(pfd[0]));
		check("Error executing execve",
			execve(cmd->access_path, cmd->opts, cmd->envp));
	}
}

void	run_commands(t_cmd *f_cmd, t_cmd *n_cmd)
{
	int	fds[2];

	if (!f_cmd || !n_cmd)
		return ;
	check("Error when using pipe", pipe(fds));
	check("Error piping[0]", fds[0]);
	check("Error piping[1]", fds[1]);
	run_first(f_cmd, fds);
	run_next(n_cmd, fds);
	check("Error when waiting child process", wait(NULL));
	check("Error closing fd", close(fds[0]));
	check("Error closing fd", close(fds[1]));
}
