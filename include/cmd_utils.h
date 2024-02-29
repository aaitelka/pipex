/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.h           	                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:16:10 by aaitelka          #+#    #+#             */
/*   Updated: 2024/02/21 17:16:12 by aaitelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_UTILS_H
# define CMD_UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

char	*get_command(const char *arg);

char	**get_options(char *av);

char	*get_path(char *ep[]);

char	*get_access_path(char *ep[], char *cmd);

#endif
