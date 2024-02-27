/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:15:44 by aaitelka          #+#    #+#             */
/*   Updated: 2024/02/21 17:15:47 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cmd_utils.h"
#include "../include/libft_utils.h"

char	*get_command(const char *arg)
{
	char	*cmd;
	int		cmd_len;

	if (!arg || !*arg)
		return (NULL);
	cmd_len = 0;
	while (arg[cmd_len] && arg[cmd_len] != ' ')
		cmd_len++;
	cmd = (char *) malloc(cmd_len + 1);
	cmd[cmd_len] = '\0';
	while (cmd_len--)
		cmd[cmd_len] = arg[cmd_len];
	return (cmd);
}

char	get_limiter(char *av)
{
	if (!av)
		return (0);
	// if (strchr(av, ' '))
	// 	av++;
	while (*av)
	{
		if ((*av == '\'' || *av == '\"'))
			return (*av);
		av++;
	}
	return (' ');
}

char	**get_options(char *av)
{
	char	**opts;

	if (!av || !*av)
		return (NULL);
	opts = ft_split(av, get_limiter(av));
	return (opts);
}

char	*get_path(char *ep[])
{
	if (!ep || !*ep)
		return (NULL);
	while (*ep)
	{
		if (strncmp(*ep, "PATH=", 5) == 0)
			return (strchr(*ep, '=') + 1);
		ep++;
	}
	return (NULL);
}

char	*get_access_path(char *path, char *cmd)
{
	char	**dirs;

	if (!path || !*cmd)
		return (NULL);
	dirs = ft_split(path, ':');
	path = NULL;
	cmd = join("/", cmd);
	while (*dirs)
	{
		path = join(*dirs, cmd);
		if (access(path, X_OK) == 0)
			return (free(cmd), path);
		dirs++;
	}
	return (NULL);
}
