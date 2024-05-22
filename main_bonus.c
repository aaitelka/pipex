/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:57:57 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/22 23:02:52 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex_bonus.h"

# define SINGLE '\''
# define DOUBLE '\"'


//int size_at(const char *str, char c)
//{
//	int len;
//
//	len = 0;
//	while (str[len] && str[len] != c)
//		len++;
//	return (len);
//}
//
// int size_from(char *str, char c)
// {
// 	int len;
// 	bool b;

// 	len = 0;
// 	b = false;
// 	str = ft_strchr(str, c);
// 	if (!str)
// 		return (len);
// 	str++;
// 	while (str[len])
// 	{
// 		if (str[len] == c)
// 			b = true;
// 		if (b &&  str[len + 1] == ' ')
// 			break;
// 		len++;
// 	}
// 	return (len);
// }
//
//static char *get_command(const char *arg)
//{
//	int i;
//	char *path;
//
//	i = 0;
//	if (arg[i] == ' ')
//	{
//		ft_printf("Error no such file or directory\n");
//		exit(EXIT_FAILURE);
//	}
//	path = malloc(size_at(arg, ' ') + 1);
//	if (!path)
//		return (NULL);
//	while (arg[i] != ' ')
//	{
//		path[i] = arg[i];
//		i++;
//	}
//	path[i] = '\0';
//	return (path);
//}
//
////static char *get_options(const char *arg)
////{
////	char *opts;
////	int i;
////
////	i = 0;
////	opts = malloc(size_from(arg, ' ') + 1);
////	if (!opts)
////		return (NULL);
////	while (arg[i])
////	{
////		opts[i] = arg[i];
////		i++;
////	}
////	opts[i] = '\0';
////	return (opts);
////}
//
//static char *get_path(char *const ep[])
//{
//	if (!ep || !*ep)
//	{
//		ft_putstr_fd("Error PATH unsetted\n", STDERR_FILENO);
//		exit(EXIT_FAILURE);
//	}
//	while (*ep)
//	{
//		if (ft_strncmp(*ep, "PATH=", 5) == 0)
//			return (ft_strchr(*ep, '=') + 1);
//		ep++;
//	}
//	return (NULL);
//}
//
//bool is_exec(const char *absolute)
//{
//	return (!access(absolute, X_OK));
//}
//
//void clear_paths(char **paths)
//{
//	int i;
//
//	if (!paths)
//		return;
//	i = 0;
//	while (paths[i])
//	{
//		free(paths[i]);
//		i++;
//	}
//	free(paths);
//}
//
//char *get_absolute(char *ep[], char *cmd)
//{
//	int i;
//	char **paths;
//	char *absolute;
//	char *temp;
//
//	i = 0;
//	paths = ft_split(get_path(ep), ':');
//	while (paths[i])
//	{
//		temp = ft_strjoin(paths[i], "/");
//		absolute = ft_strjoin(temp, cmd);
//		free(temp);
//		if (is_exec(absolute))
//			return (clear_paths(paths), absolute);
//		free(absolute);
//		i++;
//	}
//	return (NULL);
//}
//
//void	clear(t_cmd **lst)
//{
//	t_cmd	*temp;
//
//	if (!lst)
//		return ;
//	while (*lst)
//	{
//		temp = (*lst)->next;
//		free((*lst)->absolute);
//		*lst = temp;
//	}
//	lst = NULL;
//}
//
// void skip(char **str, char c)
// {
// 	while (**str == c)
// 		str[0]++;
// }
//
//void destroy(t_pipex *pipex)
//{
////	clear_paths(pipex->cmd->opts);
////	free(pipex->cmd->absolute);
////	clear_cmd(pipex->cmd);
////	clear(&(pipex->cmd));
//}
//
//void init_pipex(t_pipex *pipex, int ac, char *av[], char *ep[])
//{
//	t_cmd	*new;
//	char	**opts;
//
//	pipex->cmd = NULL;
//	int i = 2;
//	while (i < (ac - 1))
//	{
//		skip(&av[i], ' ');
//		char *relative = get_command(av[i]);
//		char *absolute = get_absolute(ep, relative);
//		free(relative);
//		char *opt = ft_strchr(av[i], ' ');
//		if (opt)
//		{
//			ft_printf("=======%s\n", opt);
//			opts = ft_split(++opt, ' ');
//		}
////		free(opt);
//		ft_printf("-----%p\n", opts[i]);
//		new = new_cmd(absolute, opts);
//		add_cmd(&(pipex->cmd), new);
//		//should free old cmd
//		i++;
//	}
//	pipex->infile = av[1];
//	pipex->outfile = av[ac - 1];
//}
//
//void leak()
//{
//	system("leaks pipex");
//}

bool	is_quot(char c)
{
	return (c == 34 || c == 39);
}

int get_substr_len(char *str, int start, char c)
{
	int len = 0;

	while (str[start])
	{
		if (str[start] == c)
			return (len);
		len++;
		start++;
	}
	return (-1);
}


void count_occur(char *str, int *single, int *dauble)
{
	*single = 0;
	*dauble = 0;
	while (*str)
	{
		if (*str == SINGLE)
			*single += 1;
		else if (*str == DOUBLE)
			*dauble += 1;
		str++;
	}
}
// 'gre"p'

void	clear_arr(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char *realoc_char(char *str, char c, int len)
{
	int		i;
	char	*new_str;

	new_str = malloc(len + 2);
	if (!new_str)
		return (NULL);
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

int arr_len(char **arr)
{
	int len;

	len = 0;
	while (arr && arr[len])
		len++;
	return (len);
}

char **realoc_array(char **arr, char *str, int len)
{
	int		i;
	char	**new_arr;

	new_arr = malloc((len + 2 )* sizeof(char*));
	if (!new_arr)
		return (NULL);
	i = 0;
	while (len && arr[i])
	{
		new_arr[i] = ft_strdup(arr[i]);
		i++;
	}
	new_arr[i] = ft_strdup(str);
	ft_printf("==> %s | %s\n",str, new_arr[i]);
	new_arr[i + 1] = NULL;
	ft_printf("in realloc len = %d\n", arr_len(new_arr));
	// clear_arr(arr);
	printf ("new ======> %p\n",new_arr);
	return (new_arr);
}
bool is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}


void tokenizer(char *str, char *result, char c, int *i)
{
	char *sub;
	char *temp;
	int len;

	len = get_substr_len(str, *i + 1, c);
	if(len == -1)
	{
		printf("Error\n");
		exit (EXIT_FAILURE);
	}
	sub = ft_substr(str, *i + 1, len);
	temp = result;
	result = ft_strjoin(temp, sub);
	free(temp);
	temp = NULL;
	i += (len + 1);
}

// void l(){system("leaks a.out");}
int main(int ac, char *av[], char *ep[])
{
	// atexit(l);
	char str1[] = "h'a\"l'em  dada ddd\"g '  gg\"dd end  ";

	char **commands = NULL;
	char *result = NULL;
	char *temp = NULL;
	char **temp2;
	char *sub;
	int i = 0;
	int len = 0;

	while (str1[i])
	{
		if (!is_space(str1[i]) && !is_quot(str1[i]))
			if (result)
				result = realoc_char(result, str1[i], (int)ft_strlen(result));
			else
				result = realoc_char(result, str1[i], 0);
		else if (str1[i] == SINGLE)
		{
			len = get_substr_len(str1, i + 1, SINGLE);
			if(len == -1)
			{
				printf("Error\n");
				exit (EXIT_FAILURE);
			}
			sub = ft_substr(str1, i + 1, len);
			temp = result;
			result = ft_strjoin( temp, sub);
			free(temp);
			temp = NULL;
			i += (len + 1);
		}
		else if (str1[i] == DOUBLE)
		{
			len = get_substr_len(str1, i + 1, DOUBLE);
			if(len == -1)
			{
				printf("Error\n");
				exit (EXIT_FAILURE);
			}
			sub = ft_substr(str1, i + 1, len);
			temp = result;
			result = ft_strjoin( temp, sub);
			free(temp);
			temp = NULL;
			i += (len + 1);
		} else if (is_space(str1[i]))
		{
			if (result)
			{
				temp2 = commands;
				commands = realoc_array(commands, result, arr_len(commands));
				clear_arr (temp2);
				temp2 = NULL;
				printf ("======> %p\n",&commands);
			}
			free(result);
			result = NULL;
		}
		i++;
	}
	if (result)
	{
		temp2 = commands;
				commands = realoc_array(commands, result, arr_len(commands));
				clear_arr (temp2);
				temp2 = NULL;
	}
	
	int l = 0;
	while (commands[l])
	{
		ft_printf("cmd %d : %s\n", l, commands[l]);
		l++;
	}
	return 0;
}
