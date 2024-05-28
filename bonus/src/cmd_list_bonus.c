/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:49:14 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/26 22:32:03 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

t_cmd	*new_cmd(char *absolute, char **opts, int pos)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->absolute = absolute;
	cmd->args = opts;
	cmd->cmd_pos = pos;
	cmd->next = NULL;
	return (cmd);
}

t_cmd	*last_cmd(t_cmd *cmd)
{
	if (!cmd)
		return (NULL);
	while (cmd->next)
		cmd = cmd->next;
	return (cmd);
}

void	add_cmd(t_cmd **cmd, t_cmd *new)
{
	t_cmd	*last;

	if (!cmd || !new)
		return ;
	last = last_cmd(*cmd);
	if (last)
		last->next = new;
	else
		*cmd = new;
}

void	clear_cmd(t_cmd *cmd)
{
	t_cmd	*current;
	t_cmd	*next;

	if (!cmd)
		return ;
	current = cmd;
	while (current)
	{
		next = current->next;
		clear_arr(current->args);
		free(current);
		current = next;
	}
}
