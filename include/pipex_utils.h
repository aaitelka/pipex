/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:10:24 by aaitelka          #+#    #+#             */
/*   Updated: 2024/02/22 20:10:25 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_UTILS_H
# define PIPEX_UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct command
{
	char	*file;
	char	*cmd;
	char	**opts;
	char	**envp;
	char	*access_path;
}			t_cmd;

t_cmd	*get_instance(char *ep[], char *file, char *cmd, char **opts);

void	run_first(t_cmd *cmd, int pfd[]);

void	run_next(t_cmd *cmd, int pfd[]);

void	run_commands(t_cmd *cmd1, t_cmd *cmd2);

void	check(char *msg, int error_code);

#endif
