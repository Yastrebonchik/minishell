# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcedra <kcedra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/06 17:59:06 by cdelicia          #+#    #+#              #
#    Updated: 2020/10/24 16:39:34 by kcedra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean bonus re

NAME = libft.a
WWW = -Wall -Wextra -Werror
HEADER = ./
MAIN_FUNCTIONS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
                ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
                ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
                ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
                ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c \
                ft_split.c ft_itoa.c ft_strjoin.c ft_strtrim.c ft_strmapi.c \
                ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
                ft_realloc.c ft_strchrnum.c
MAIN_OBJECTS = $(MAIN_FUNCTIONS:.c=.o)

BONUS_FUNCTIONS = ft_lstnew.c ft_lstclear.c ft_lstadd_front.c ft_lstadd_back.c \
                ft_lstdelone.c ft_lstsize.c ft_lstlast.c ft_lstiter.c ft_lstmap.c \
                get_next_line.c get_next_line_utils.c
BONUS_OBJECTS = $(BONUS_FUNCTIONS:.c=.o)

all: $(NAME)

$(NAME):
	@gcc $(WWW) -c $(MAIN_FUNCTIONS) -I $(HEADER)
	@ar rcs $(NAME) $(MAIN_OBJECTS)

clean:
	@rm -f $(MAIN_OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus:
	@gcc $(WWW) -c $(BONUS_FUNCTIONS) -I $(HEADER)
	@ar rcs $(NAME) $(BONUS_OBJECTS)
    