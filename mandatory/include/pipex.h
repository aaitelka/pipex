/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:49:39 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/26 23:03:22 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../../libs/libft/libft.h"

# define ERR_ARGS "pipex: option requires args ./pipex inf cmd1 cmd2 outf\n"
# define ERR_MALLOC  "malloc failed!\n"
# define ERR_QUOTES  "quote not closed!\n"
# define ERR_WAITPID "wait pid failed\n"
# define ERR_PIPING "error piping\n"
# define ERR_FORKING "error fork new process\n"
# define ERR_CLOSE_FD "error closing fd\n"
# define ERR_DUP_FD "error when duplicating fd\n"

typedef struct s_cmd
{
	char			*absolute;
	char			**args;
	int				cmd_pos;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_pipex
{
	t_cmd	*cmd;
	char	*infile;
	char	*outfile;
	char	**envp;
	int		cmds;
	int		pfd[2];
}	t_pipex;

t_cmd	*last_cmd(t_cmd *cmd);
t_cmd	*new_cmd(char *absolute, char **opts, int pos);
void	add_cmd(t_cmd **cmd, t_cmd *new);
void	clear_cmd(t_cmd *cmd);
void	execute(t_pipex *pipex);
char	**parse_commands(char *input);
char	*get_absolute(char **ep, char *cmd);
int		get_size(char **arr);
void	clear_arr(char **map);
void	cmd_not_found(char *cmd);
void	assert_null(void *any, char *msg);
void	assert_error(int err, char *msg);

#endif
