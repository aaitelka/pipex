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

LIBFT	:=	libft

CC		:=	cc

CFLAGS	:=	-Wall -Wextra -Werror

RM		:=	rm -rf

INCLUDE	:=	include/pipex.h \
			include/cmd_utils.h \
			include/pipex_utils.h

SRCS	:=	pipex.c \
			src/cmd_utils.c \
			src/pipex_utils.c

OBJS	:=	$(SRCS:%c=%o)

all		: $(NAME)

%o		: %c  $(INCLUDE)
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME)	: $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT)/libft.a $^ -o $@

clean	:
	$(MAKE) -C $(LIBFT) clean
	$(RM) $(OBJS)

fclean	: clean
	$(MAKE) -C $(LIBFT) fclean
	$(RM) $(NAME)

re	: fclean all
