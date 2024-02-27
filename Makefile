# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 01:55:36 by aaitelka          #+#    #+#              #
#    Updated: 2024/02/19 02:01:31 by aaitelka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	pipex
HEAD	:=	include/pipex.h \
			include/cmd_utils.h \
			include/libft_utils.h \
			include/pipex_utils.h
CC		:=	cc
CFLAGS	:=	-Wall -Wextra -Werror
RM		:=	rm -rf
SRC		:=	pipex.c \
			src/cmd_utils.c \
			src/libft_utils.c \
			src/pipex_utils.c
OBJ		:=	$(SRC:%c=%o)

all	: $(NAME)

%o	: %c $(HEAD)
	$(CC) $(CFLAGS) $< -c $@

$(NAME)	: $(OBJ) $(HEAD)
	$(CC) $(CFLAGS) $^ -o $@

clean	:
	$(RM) $(OBJ)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all
