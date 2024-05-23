/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:57:57 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/23 16:43:32 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex_bonus.h"

void l(){system("leaks a.out");}
int main(int ac, char *av[], char *ep[])
{
	atexit(l);
	char *str1 = ft_strtrim(av[1], " ");

	
	char **commands = parse_commands(str1);
	int l = 0;
	while (commands[l])
	{
		ft_printf("cmd %d : %s\n", l, commands[l]);
		l++;
	}
	clear_arr(commands);
	free(str1);
	return 0;
}
