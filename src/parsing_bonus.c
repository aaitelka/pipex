/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:03:43 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/23 19:07:20 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static int	get_substr_len(char *str, int start, char c)
{
	int	len;

	len = 0;
	while (str && str[start])
	{
		if (str[start] == c)
			return (len);
		len++;
		start++;
	}
	return (-1);
}

static char	*add_char(char *str, char c, int len)
{
	int		i;
	char	*new_str;

	new_str = malloc(len + 2);
	assert_null(new_str, ERR_MALLOC);
	i = 0;
	while (len && str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = c;
	new_str[i + 1] = '\0';
	if (len)
		free(str);
	return (new_str);
}

static char	**add_str(char **arr, char *str, int len)
{
	int		i;
	char	**new_arr;

	new_arr = malloc((len + 2) * sizeof(char *));
	assert_null(new_arr, ERR_MALLOC);
	i = 0;
	while (len && arr[i])
	{
		new_arr[i] = ft_strdup(arr[i]);
		i++;
	}
	new_arr[i] = ft_strdup(str);
	new_arr[i + 1] = NULL;
	clear_arr(arr);
	return (new_arr);
}

static void	append_sub_quotes(char **result, char *str, int *i)
{
	int		len;
	char	*sub;
	char	*temp;

	len = get_substr_len(str, *i + 1, str[*i]);
	assert_error(len, ERR_QUOTES);
	sub = ft_substr(str, *i + 1, len);
	assert_null(sub, ERR_MALLOC);
	temp = *result;
	*result = ft_strjoin(temp, sub);
	assert_null(sub, ERR_MALLOC);
	free(temp);
	temp = NULL;
	*i += (len + 1);
	free(sub);
}

char	**parse_commands(char *input)
{
	char	**cmds;
	char	*result;
	int		i;

	cmds = NULL;
	result = NULL;
	i = -1;
	while (input[++i])
	{
		if (!ft_isspace(input[i]) && !ft_isquote(input[i]))
			result = add_char(result, input[i], (int)ft_strlen(result));
		else if (ft_isquote(input[i]))
			append_sub_quotes(&result, input, &i);
		else if (ft_isspace(input[i]))
		{
			if (result)
				cmds = add_str(cmds, result, get_size(cmds));
			free(result);
			result = NULL;
		}
	}
	if (result)
		cmds = add_str(cmds, result, get_size(cmds));
	free(result);
	return (cmds);
}
