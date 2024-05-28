/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:07:12 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/28 15:13:45 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static int	has_slash(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

static void	run_first(t_pipex *pipex, t_cmd *cmd)
{
	pid_t	pid;
	int		fd;
	char	*absolute;

	pid = fork();
	assert_error(pid, ERR_FORKING);
	if (pid == 0)
	{
		fd = open(pipex->infile, O_RDONLY);
		assert_error(fd, pipex->infile);
		assert_error(dup2(fd, STDIN_FILENO), ERR_DUP_FD);
		assert_error(close(fd), ERR_CLOSE_FD);
		if (has_slash(cmd->args[0]))
		{
			absolute = ft_strdup(cmd->args[0]);
			assert_null(absolute, ERR_MALLOC);
		}
		else
			absolute = get_absolute(pipex->envp, cmd->args[0]);
        assert_error(close(pipex->pfd[0]), ERR_CLOSE_FD);
		assert_error(dup2(pipex->pfd[1], STDOUT_FILENO), ERR_DUP_FD);
		assert_error(close(pipex->pfd[1]), ERR_CLOSE_FD);
		assert_error(execve(absolute, cmd->args, pipex->envp), cmd->args[0]);
	}
}

static void	run_last(t_pipex *pipex, t_cmd *cmd)
{
	pid_t	pid;
	int		fd;
	char	*absolute;

	pid = fork();
	assert_error(pid, ERR_FORKING);
	if (pid == 0)
	{
		fd = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		assert_error(fd, pipex->outfile);
		if (has_slash(cmd->args[0]))
		{
			absolute = ft_strdup(cmd->args[0]);
			assert_null(absolute, ERR_MALLOC);
		}
		else
			absolute = get_absolute(pipex->envp, cmd->args[0]);
		assert_error(dup2(fd, STDOUT_FILENO), ERR_DUP_FD);
		assert_error(close(fd), ERR_CLOSE_FD);
		assert_error(execve(absolute, cmd->args, pipex->envp), cmd->args[0]);
	}
}

void	execute(t_pipex *pipex)
{
	t_cmd	*cmd;

	cmd = pipex->cmd;
	while (cmd)
	{
		if (cmd->cmd_pos > 0)
		{
			assert_error(dup2(pipex->pfd[0], STDIN_FILENO), ERR_DUP_FD);
			assert_error(close(pipex->pfd[0]), ERR_CLOSE_FD);
		}
		if (cmd->next != NULL)
			assert_error(pipe(pipex->pfd), ERR_PIPING);
		if (cmd->cmd_pos == 0)
			run_first(pipex, cmd);
		else if (cmd->next == NULL)
			run_last(pipex, cmd);
        if (cmd->next != NULL)
			assert_error(close(pipex->pfd[1]), ERR_CLOSE_FD);
		cmd = cmd->next;
	}
}
