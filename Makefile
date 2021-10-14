# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcedra <kcedra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/18 14:10:32 by cdelicia          #+#    #+#              #
#    Updated: 2020/11/20 14:45:54 by kcedra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re debug

NAME = minishell

CC = gcc

FLAGS = -Wall -Wextra -Werror

DEBUG = -g -Wall -Wextra -Werror

HEADER = minishell.h

LIBFTDIR = libft/

LIBFT = libft.a

SRCS = main.c built_in.c env_utils.c free.c lst.c init.c check.c split.c fix_content.c \
export_utils.c unset_utils.c path_utils.c execute_command_utils.c \
execute_binary.c execute_command.c redirect.c exit.c readline.c fix_quotes.c \
cd_utils.c var_assign_utils.c signals.c syntax.c norm.c

OBJS = $(SRCS:.c=.o)

%.o: %.c $(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME) $(HEADER)

$(NAME): $(OBJS)
	@make -C $(LIBFTDIR)
	@mv $(LIBFTDIR)$(LIBFT) .
	@$(CC) $(FLAGS) $(OBJS) -L. -lft -o $(NAME)
	#$(CC) $(DEBUG) $(OBJS) -L. -lft -o $(NAME)

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFTDIR)
	
fclean: clean
	@rm -f minishell
	@make fclean -C $(LIBFTDIR)
	@rm -f libft.a

re: fclean all
