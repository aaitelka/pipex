/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:49:39 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/26 22:23:24 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "pipex_types_bonus.h"
# include "../../libs/libft/libft.h"

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