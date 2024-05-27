# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaitelka <aaitelka@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/24 22:36:23 by aaitelka          #+#    #+#              #
#    Updated: 2024/05/26 23:02:56 by aaitelka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN :=	\033[0;32m
RED := \033[0;31m
NC :=	\033[0m

NAME	:=	pipex
B_NAME	:= pipex_bonus
CC		:=	cc
CFLAGS	:=	-Wall -Wextra -Werror
LIBFT 	:= ./libs/libft
HEADS := -I ./mandatory/include -I $(LIBFT)
B_HEADS := -I ./bonus/include -I $(LIBFT)
LIBS := $(LIBFT)/libft.a

SRCS	:=	mandatory/main.c \
			mandatory/src/assert.c \
			mandatory/src/parsing.c \
			mandatory/src/cmd_list.c \
			mandatory/src/arr_utils.c \
			mandatory/src/executing.c  \
			mandatory/src/pipex_utils.c \

OBJS	:=	$(SRCS:%.c=%.o)

B_SRCS	:=	bonus/main_bonus.c \
			bonus/src/assert_bonus.c \
			bonus/src/parsing_bonus.c \
			bonus/src/cmd_list_bonus.c \
			bonus/src/arr_utils_bonus.c \
			bonus/src/executing_bonus.c  \
			bonus/src/pipex_utils_bonus.c \

B_OBJS	:=	$(B_SRCS:%_bonus.c=%_bonus.o)

all : libft $(NAME)

%.o : %.c $(HEADS)
	@echo "$(GREEN)Generate : $@"
	@$(CC) $(CFLAGS) -o $@ -c $<

libft:
	@$(MAKE) --no-print-directory -C $(LIBFT) -j4

$(NAME) : $(OBJS)
	@echo "$(GREEN)Linking $@ executable...$(NC)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@

%_bonus.o : %_bonus.c $(B_HEADS)
	@echo "$(GREEN)Generate bonus: $@"
	@$(CC) $(CFLAGS) $(B_HEADS) -o $@ -c $<

bonus : libft $(B_NAME)

$(B_NAME) : $(B_OBJS)
	@echo "$(GREEN)Linking $@ executable...$(NC)"
	@$(CC) $(CFLAGS) $(B_OBJS) $(LIBS) -o $@

clean :
	@echo "$(RED) $@...$(NC)"
	@$(MAKE) --no-print-directory -C $(LIBFT) clean
	@$(RM) $(OBJS) $(B_OBJS)

fclean : clean
	@echo "$(RED)Full $<...$(NC)"
	@$(MAKE) --no-print-directory -C $(LIBFT) fclean
	@echo "$(RED)rm -f pipex$(NC)"
	@$(RM) $(NAME) $(B_NAME)

re : fclean all