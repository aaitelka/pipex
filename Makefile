# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/24 22:36:23 by aaitelka          #+#    #+#              #
#    Updated: 2024/05/24 22:47:22 by aaitelka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN	:=	\033[0;32m
NC		:=	\033[0m

NAME	:=	pipex
CC		:=	cc
CFLAGS	:=	-Wall -Wextra -Werror
LIBFT 	:= ./libs/libft
HEADS := -I ./include -I $(LIBFT)

SRCS	:=	main_bonus.c \
			src/assert_bonus.c \
			src/parsing_bonus.c \
			src/cmd_list_bonus.c \
			src/arr_utils_bonus.c \

OBJS	:=	$(SRCS:%.c=%.o)

# B_SRCS	:=	bonus/checker_bonus.c \
# 			bonus/src/libft_bonus.c \
# 			bonus/src/parsing_bonus.c \
# 			bonus/src/helpers_bonus.c \
# 			bonus/src/instructions_bonus.c \

# B_OBJS	:=	$(B_SRCS:%_bonus.c=%_bonus.o)

all : libft $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	@$(MAKE) --no-print-directory -C $(LIBFT) -j4

$(NAME): 		$(OBJS)
				@echo "$(GREEN)==========| Linking $(NAME) executable... |==========$(NC)"
				$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@

$(LIBFT) :
				@echo "$(GREEN)==========| Compiling libft... |==========$(NC)"
				$(MK_LBFT)
				@echo "$(GREEN)==========| Compiling libft bonus... |==========$(NC)"
				$(MK_LBFT) bonus

clean		:
				@echo "$(GREEN)==========| Cleaning... |==========...$(NC)"
				$(MK_LBFT) clean
				$(RM) $(OBJS) $(B_OBJS)

fclean :		clean
				@echo "$(GREEN)==========| Full Cleaning... |==========$(NC)"
				$(MK_LBFT) fclean
				$(RM) $(NAME) $(CHECKER)

re		:		fclean all