/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:49:39 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/23 16:41:20 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include "types_bonus.h"
#include "../libs/libft/libft.h"
/**
 * CMD LIST
 */
t_cmd	*last_cmd(t_cmd *cmd);
t_cmd	*new_cmd(char *absolute, char **opts);
void	add_cmd(t_cmd **cmd, t_cmd *new);
void	clear_cmd(t_cmd *cmd);
/**
 * PARSINGE
 */
char	**parse_commands(char *input);
/**
 * ARRAY UTILS
 */
int		get_size(char **arr);
void	clear_arr(char **map);
/**
 * ASSERTION
 */
void	assert_null(void *any, char *msg);
void	assert_error(int errno, char *msg);
/**
 * HEPERS
 */
bool	is_quote(char c);
bool	is_space(char c);

#endif
