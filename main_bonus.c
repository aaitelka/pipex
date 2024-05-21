/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:57:57 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/19 16:57:58 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex_bonus.h"

# define SINGLE '\''
# define DOUBLE '\"'

bool	is_quot(char c)
{
	return (c == 34 || c == 39);
}
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
int size_from(char *str, char c)
{
	int len;
	bool b;

	len = 0;
	b = false;
	str = ft_strchr(str, c);
	if (!str)
		return (len);
	str++;
	while (str[len])
	{
		if (str[len] == c)
			b = true;
		if (b &&  str[len + 1] == ' ')
			break;
		len++;
	}
	return (len);
}
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
void skip(char **str, char c)
{
	while (**str == c)
		str[0]++;
}
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

int get_next_occurenc(char *str, int start, char c)
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

int main(int ac, char *av[], char *ep[])
{


	char *str = ft_strtrim(av[2], " ");

	int start = (int) ((ft_strchr(str, SINGLE)) - str);
	ft_printf("len = %d\n", start);

	int len = get_next_occurenc(str, start + 1, SINGLE);

	char *sub = ft_substr(str, start + 1, len);
	char *s1 = NULL;
	char *s = ft_strjoin(s1, sub);

	ft_printf("command and options => %s\n", s);

	return 0;
}
