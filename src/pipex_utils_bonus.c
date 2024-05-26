/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:05:07 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/26 16:05:07 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static char *get_path(char **ep)
{
    while (ep && *ep)
    {
        if (ft_strncmp(*ep, "PATH=", 5) == 0)
            return (ft_strchr(*ep, '=') + 1);
        ep++;
    }
    return (NULL);
}

char *get_absolute(char **ep, char *cmd)
{
    int		i;
    char	**paths;
    char	*path;
    char	*absolute;
    char	*temp;

    i = 0;
    path = get_path(ep);
    if (!path)
        return (ft_strdup(cmd));
    paths = ft_split(path, ':');
    assert_null(paths, ERR_MALLOC);
    while (paths[i])
    {
        temp = ft_strjoin(paths[i], "/");
        assert_null(temp, ERR_MALLOC);
        absolute = ft_strjoin(temp, cmd);
        assert_null(absolute, ERR_MALLOC);
        free(temp);
        if (!access(absolute, X_OK))
            return (clear_arr(paths), absolute);
        free(absolute);
        i++;
    }
    return (NULL);
}
