/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcedra <kcedra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:10:40 by cdelicia          #+#    #+#             */
/*   Updated: 2020/10/24 16:53:51 by kcedra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HEADER_H
# define MAIN_HEADER_H

# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include <signal.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <errno.h>
# include <string.h>

# define carriage_return '\13'

typedef struct					s_command_list
{
	int							id;
	int							redir_id;
	char						*str;
	int							prev_pipe;
	struct s_command_list		*next;
	struct s_command_list		*previous;
}								t_command_list;

typedef struct					s_main
{
	int							fd;
	const char					*line;
	t_command_list				parce_list;
}								t_main;

typedef struct					s_env
{
	int							visible;
	char						*key;
	char						*value;
	struct s_env				*next;
}								t_env;

void							echo(char **cur_command);
void							pwd();
void							env_print(t_env *env);
void							env_transform(char **envp, t_env **env);

#endif