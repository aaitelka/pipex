/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:49:14 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/19 19:49:14 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

t_cmd	*new_cmd(char *absolute, char **opts)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->absolute = absolute;
	cmd->opts = opts;
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
