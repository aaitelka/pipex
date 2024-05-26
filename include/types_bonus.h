/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:53:17 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/24 22:02:01 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_TYPES_BONUS_H
# define PIPEX_TYPES_BONUS_H

# define ERR_MALLOC  "malloc failed!\n"
# define ERR_QUOTES  "quote not closed!\n"
# define ERR_WAITPID "wait pid failed\n"
# define ERR_PIPING "error piping\n"
# define ERR_FORKING "error fork new process\n"
# define ERR_CLOSE_FD "error closing fd\n"
# define ERR_DUP_FD "error when duplicating fd\n"

typedef struct s_cmd
{
	char			*absolute;
	char			**args;
	int				pos;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_pipex
{
	t_cmd	*cmd;
	char	*infile;
	char	*outfile;
	char	**envp;
	int 	cmds;
	int		pfd[2];
}	t_pipex;

#endif
