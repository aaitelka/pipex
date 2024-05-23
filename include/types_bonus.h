/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:53:17 by aaitelka          #+#    #+#             */
/*   Updated: 2024/05/23 16:38:38 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_TYPES_BONUS_H
#define PIPEX_TYPES_BONUS_H

# define ERR_MALLOC  "malloc failed!\n"

typedef struct s_cmd
{
	char			*absolute;
	char			**opts;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_pipex
{
	t_cmd	*cmd;
	char	*infile;
	char	*outfile;
}	t_pipex;

#endif
