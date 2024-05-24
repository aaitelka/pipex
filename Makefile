# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/24 22:36:23 by aaitelka          #+#    #+#              #
#    Updated: 2024/05/24 23:54:21 by aaitelka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN :=	\033[0;32m
RED := \033[0;31m
NC :=	\033[0m

NAME	:=	pipex
CC		:=	cc
CFLAGS	:=	-Wall -Wextra -Werror
LIBFT 	:= ./libs/libft
HEADS := -I ./include -I $(LIBFT)
LIBS := $(LIBFT)/libft.a

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
	@echo "$(GREEN)Generate : $@"
	@$(CC) $(CFLAGS) $(HEADS) -o $@ -c $<

libft:
	@$(MAKE) --no-print-directory -C $(LIBFT) -j4

$(NAME) : $(OBJS)
	@echo "$(GREEN)Linking $(NAME) executable...$(NC)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@

clean :
	@echo "$(RED) $@...$(NC)"
	@$(MAKE) --no-print-directory -C $(LIBFT) clean
	@$(RM) $(OBJS) #$(B_OBJS)

fclean : clean
	@echo "$(RED)Full $<...$(NC)"
	@$(MAKE) --no-print-directory -C $(LIBFT) fclean
	@echo "$(RED)rm -f pipex$(NC)"
	@$(RM) $(NAME)

re : fclean all