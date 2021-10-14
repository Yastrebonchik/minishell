# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdelicia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/06 17:59:06 by cdelicia          #+#    #+#              #
#    Updated: 2020/11/11 20:06:32 by cdelicia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libft.a
WWW = -Wall -Wextra -Werror
HEADER = ./libft.h
MAIN_FUNCTIONS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
                ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
                ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
                ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
                ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c \
                ft_split.c ft_itoa.c ft_strjoin.c ft_strtrim.c ft_strmapi.c \
                ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
                ft_realloc.c ft_strchrnum.c ft_lstnew.c ft_lstclear.c ft_lstadd_front.c \
                ft_lstadd_back.c ft_lstdelone.c ft_lstsize.c ft_lstlast.c ft_lstiter.c \
                ft_lstmap.c get_next_line.c get_next_line_utils.c ft_split_set.c \
                ft_check_echo.c ft_split_echo.c
MAIN_OBJECTS = $(MAIN_FUNCTIONS:.c=.o)

all: $(NAME)

%.o: %.c
	@gcc $(WWW) -c $< -o $@

$(NAME): $(MAIN_OBJECTS)
	@ar rcs $(NAME) $(MAIN_OBJECTS)

clean:
	@rm -f $(MAIN_OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
    