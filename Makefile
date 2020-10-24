# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcedra <kcedra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/18 14:10:32 by cdelicia          #+#    #+#              #
#    Updated: 2020/10/24 16:56:32 by kcedra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = minishell

CC = gcc

FLAGS = -Wall -Wextra -Werror

DEBUG = -g -Wall -Wextra -Werror

HEADER = minishell.h

LIBFTDIR = libft/

LIBFT = libft.a

SRCS = main.c built_in.c env_utils.c

OBJS = $(SRCS:.c=.o)

%.o: %.c $(HEADER)
		$(CC) $(FLAGS) -c $< -o $@

all: $(NAME) $(HEADER)
	
$(NAME): $(OBJS)
	make -C $(LIBFTDIR)
	mv $(LIBFTDIR)$(LIBFT) .
	$(CC) $(FLAGS) $(OBJS) -L. -lft -o $(NAME)

clean:
	rm -f *.o
	make clean -C $(LIBFTDIR)
	
fclean: clean
	rm -f minishell
	make fclean -C $(LIBFTDIR)
	rm -f *.a

re: fclean all
