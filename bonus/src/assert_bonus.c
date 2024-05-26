/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:30:41 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/26 22:31:44 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	assert_null(void *any, char *msg)
{
	if (!any)
	{
		ft_putstr_fd("Error: ", STDERR_FILENO);
		ft_putstr_fd(msg, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

void	assert_error(int err, char *msg)
{
	if (err == -1)
	{
		ft_putstr_fd("pipex: ", STDERR_FILENO);
		perror(msg);
		exit(EXIT_FAILURE);
	}
}

void	cmd_not_found(char *cmd)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	exit(127);
}