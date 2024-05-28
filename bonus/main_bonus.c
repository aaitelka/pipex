/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:57:57 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/28 21:29:25 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex_bonus.h"

void	init_pipex(t_pipex *pipex, int ac, char **av, char **ep)
{
	t_cmd	*new;
	char	**opts;
	int		i;

	i = 2;
	pipex->cmd = NULL;
	if (ft_strcmp(av[1], "here_doc") == 0)
		i++;
	while (av[i] && i < (ac - 1))
	{
		opts = parse_commands(av[i]);
		new = new_cmd(opts, i - 2);
		assert_null(new, ERR_MALLOC);
		add_cmd(&pipex->cmd, new);
		i++;
	}
	pipex->infile = av[1];
	pipex->outfile = av[ac - 1];
	pipex->envp = ep;
	pipex->limiter = av[2];
	if (ft_strcmp(av[1], "here_doc") == 0)
		pipex->cmds = (ac - 4);
	else
		pipex->cmds = (ac - 3);
}

void	wait_child(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmds)
	{
		assert_error(waitpid(-1, NULL, 0), ERR_WAITPID);
		i++;
	}
}

void	here_doc(t_pipex *pipex)
{
	int		wfd;
	int		rfd;
	char	*buffer;
	char	*limiter;

	wfd = open("here_doc", O_WRONLY | O_CREAT, 0644);
	limiter = pipex->limiter;
	limiter = ft_strjoin(limiter, "\n");
	assert_null(limiter, ERR_MALLOC);
	buffer = get_next_line(STDIN_FILENO);
	while (buffer)
	{
		if (!ft_strcmp(buffer, limiter))
			break ;
		write(wfd, buffer, ft_strlen(buffer));
		free(buffer);
		buffer = get_next_line(STDIN_FILENO);
	}
	free(buffer);
	free(limiter);
	close(wfd);
	rfd = open("here_doc", O_RDONLY);
	pipex->hrdc_fd = dup(rfd);
	unlink("here_doc");
	close(rfd);
}

int	main(int ac, char **av, char **ep)
{
	t_pipex	pipex;

	if ((ft_strcmp(av[1], "here_doc") != 0 && ac >= 5)
		|| (ft_strcmp(av[1], "here_doc") == 0 && ac < 6))
	{
		pipex.stdin_fd = dup(STDIN_FILENO);
		init_pipex(&pipex, ac, av, ep);
		if (!ft_strcmp(av[1], "here_doc"))
		{
			here_doc(&pipex);
			execute(&pipex, true);
		}
		else
			execute(&pipex, false);
		dup2(pipex.stdin_fd, STDIN_FILENO);
		close(pipex.stdin_fd);
		wait_child(&pipex);
		clear_cmd(pipex.cmd);
	}
	else
	{
		ft_putstr_fd(ERR_ARGS, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
