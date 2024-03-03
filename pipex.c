/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:19:04 by aaitelka          #+#    #+#             */
/*   Updated: 2024/02/20 22:19:07 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"
#include "include/cmd_utils.h"
#include "include/pipex_utils.h"

void	run(char *av[], char *ep[])
{
	t_cmd	*first_cmd;
	t_cmd	*next_cmd;

	first_cmd = NULL;
	next_cmd = NULL;
	first_cmd = get_instance(
			ep,
			av[1],
			get_command(av[2]),
			get_options(av[2]));
	next_cmd = get_instance(
			ep,
			av[4],
			get_command(av[3]),
			get_options(av[3]));
	run_commands(first_cmd, next_cmd);
//	free(first_cmd->cmd);
//	free(first_cmd->opts);
//	free(first_cmd->access_path);
//	free(first_cmd);
//	free(next_cmd->cmd);
//	free(next_cmd->opts);
//	free(next_cmd->access_path);
//	free(next_cmd);
}

void leaks()
{
	system("leaks pipex");
}

int	main(int argc, char *argv[], char *envp[])
{
//	atexit(leaks);
	if (!argv || !envp)
		exit(EXIT_FAILURE);
	if (argc == 5 && *argv[1] && *argv[2] && *argv[3] && *argv[4])
	{
		run(argv, envp);
		exit(EXIT_SUCCESS);
	}
	else
		printf("Too few arguments, should run it like this:\n"
			"./pipex [infile] [cmd1] [cmd1] [outfile]\n");
//	check("Error unlinking file", unlink(argv[1]));
//	check("Error unlinking file", unlink(argv[4]));
}
