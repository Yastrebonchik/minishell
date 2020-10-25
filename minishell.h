/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:10:40 by cdelicia          #+#    #+#             */
/*   Updated: 2020/10/25 03:43:25 by cdelicia         ###   ########.fr       */
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

typedef struct					s_cmd_list
{
	char						*content;
	int							list_id;
	int							redir_id;
	int							pre_pipe;
	struct s_cmd_list				*next;
	struct s_cmd_list				*prev;
}								t_cmd_list;

typedef struct					s_env
{
	int							visible;
	char						*key;
	char						*value;
	struct s_env				*next;
}								t_env;

typedef struct					s_main
{
	int							fd[2];
	int							input;
	int							output;
	char						separator;
	t_cmd_list					*list;
	t_env						*env;
}								t_main;

t_main							*g_main_ptr;     /*global pointer to main*/
char							**g_line;        /*global str pointer*/

void							echo(char **cur_command);
void							pwd();
void							input_calling(char *s);
void							env_print(t_env *env);
char							*skip_whitespaces(char *line);
int								read_line(char *line, t_main *data);
char							*delete_whitespaces(char *line);
void							clear_parced_data(t_main *main);
void							free_all_array_elements(char **arr, int i);
int								array_len(char **cur_commands);
int								ft_parcing(t_main *data);
int								ft_check_command(char *s);
void							initialization_all(t_main *main);
void							env_transform(char **envp, t_env **env);

#endif