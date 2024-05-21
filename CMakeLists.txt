cmake_minimum_required(VERSION 3.26)
project(pipex C)

set(CMAKE_C_STANDARD 99)

add_executable(pipex
        main_bonus.c
        src/cmd_list_bonus.c
        include/pipex_bonus.h
        include/types_bonus.h
        src/parsing_bonus.c
        libs/libft/ft_isalpha.c
        libs/libft/ft_isdigit.c
        libs/libft/ft_isalnum.c
        libs/libft/ft_isascii.c
        libs/libft/ft_isprint.c
        libs/libft/ft_strlen.c
        libs/libft/ft_toupper.c
        libs/libft/ft_tolower.c
        libs/libft/ft_strchr.c
        libs/libft/ft_strrchr.c
        libs/libft/ft_strcmp.c
        libs/libft/ft_strncmp.c
        libs/libft/ft_strlcpy.c
        libs/libft/ft_memset.c
        libs/libft/ft_bzero.c
        libs/libft/ft_memcpy.c
        libs/libft/ft_memchr.c
        libs/libft/ft_memcmp.c
        libs/libft/ft_memmove.c
        libs/libft/ft_strlcat.c
        libs/libft/ft_strnstr.c
        libs/libft/ft_atoi.c
        libs/libft/ft_calloc.c
        libs/libft/ft_strdup.c
        libs/libft/ft_substr.c
        libs/libft/ft_strjoin.c
        libs/libft/ft_strtrim.c
        libs/libft/ft_split.c
        libs/libft/ft_itoa.c
        libs/libft/ft_strmapi.c
        libs/libft/ft_striteri.c
        libs/libft/ft_putchar_fd.c
        libs/libft/ft_putstr_fd.c
        libs/libft/ft_putendl_fd.c
        libs/libft/ft_putnbr_fd.c
        libs/libft/ft_printf.c
        libs/libft/src/put_nbr.c
        libs/libft/src/put_char.c
        libs/libft/src/put_str.c
        libs/libft/src/put_hex.c
        libs/libft/get_next_line.c
        libs/libft/get_next_line_utils.c)
