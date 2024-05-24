/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:57:57 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/24 22:28:09 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex_bonus.h"

void l(){system("leaks a.out");}

void init_pipex(t_pipex *pipex, int ac, char **av, char **ep)
{
	t_cmd	*new;
	char	**opts;
	int		i;

	i = 2;
	pipex->cmd = NULL;
	while (av[i] && i < (ac - 1))
	{
		opts = parse_commands(av[i]);
		new = new_cmd(NULL, opts, i - 2);
		assert_null(new, ERR_MALLOC);
		add_cmd(&pipex->cmd, new);
		i++;
	}
	pipex->infile = av[1];
	pipex->outfile = av[ac - 1];
	pipex->envp = ep;
	 pipex->cmds = (ac - 3);
}
static char *get_path(char **ep)
{
	// if (!ep || !*ep)
	// {
	// 	ft_putstr_fd("Error PATH unsetted\n", STDERR_FILENO);
	// 	exit(EXIT_FAILURE);
	// }
	while (ep && *ep)
	{
		if (ft_strncmp(*ep, "PATH=", 5) == 0)
			return (ft_strchr(*ep, '=') + 1);
		ep++;
	}
	return (NULL);
}

char *get_absolute(char **ep, char *cmd)
{
	int		i;
	char	**paths;
	char	*path;
	char	*absolute;
	char	*temp;

	i = 0;
	path = get_path(ep);
	if (!path)
		return (ft_strdup(cmd));
	paths = ft_split(path, ':');
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		absolute = ft_strjoin(temp, cmd);
		free(temp);
		if (!access(absolute, X_OK))
			return (clear_arr(paths), absolute);
		free(absolute);
		i++;
	}
	return (NULL);
}

// void open_infile(t_pipex *pipex)
// {
// 	int	fd;
	
// 	fd = open(pipex->infile, O_RDONLY);
// 	if (fd == -1)
// 	{
// 		clear_cmd(pipex->cmd);
// 	}
// }

void	run_first(t_pipex *pipex, t_cmd *cmd)
{
	pid_t	pid;
	int		fd;
	char	*absolute;

	pid = fork();
	if (pid == 0)
	{
		fd = open(pipex->infile, O_RDONLY);
		absolute = get_absolute(pipex->envp, cmd->opts[0]);
		dup2(fd, STDIN_FILENO);
		close(fd);
		close(pipex->pfd[0]);
		dup2(pipex->pfd[1], STDOUT_FILENO);
		close(pipex->pfd[1]);
		execve(absolute, cmd->opts, pipex->envp);
	}
}

void	run_next(t_pipex *pipex, t_cmd *cmd)
{
	pid_t	pid;
	char	*absolute;

	pid = fork();
	if (pid == 0)
	{
		absolute = get_absolute(pipex->envp, cmd->opts[0]);
		ft_printf("-\n");
		if (pipex->cmd->pos % 2 == 0)
		{
			ft_printf("1\n");
		}
		else
		{
			ft_printf("2\n");
		}
		dup2(pipex->pfd[1], STDOUT_FILENO);
		close(pipex->pfd[0]);
		close(pipex->pfd[1]);
		close(pipex->pfd[1]);
		close(pipex->pfd[0]);
		execve(absolute, cmd->opts, pipex->envp);
	}
}

void	run_last(t_pipex *pipex, t_cmd *cmd)
{
	pid_t	pid;
	int		fd;
	char	*absolute;

	pid = fork();
	if (pid == 0)
	{
		fd = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		absolute = get_absolute(pipex->envp, cmd->opts[0]);
		dup2(fd, STDOUT_FILENO);
		close(fd);
		close(pipex->pfd[1]);
		dup2(pipex->pfd[0], STDIN_FILENO);
		close(pipex->pfd[0]);
		execve(absolute, cmd->opts, pipex->envp);
	}
}

void	execute(t_pipex *pipex)
{
	t_cmd	*cmd;

	cmd = pipex->cmd;
	pipe(pipex->pfd);
	dup2(pipex->pfd[0], STDIN_FILENO);
	while (cmd)
	{
		if (!(cmd->pos))
		{
			run_first(pipex, cmd);
		}
		else if (!(cmd->next))
		{
			run_last(pipex, cmd);
		}
		else
			run_next(pipex, cmd);
		cmd = cmd->next;
	}
}

int main(int ac, char **av, char **ep)
{
	// atexit(l);

	t_pipex pipex;
	init_pipex(&pipex, ac, av, ep);
	execute(&pipex);
	clear_cmd(pipex.cmd);
	return 0;
}
