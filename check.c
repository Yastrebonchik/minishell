/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcedra <kcedra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 01:05:37 by cdelicia          #+#    #+#             */
/*   Updated: 2020/11/15 18:42:14 by kcedra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_check_command(char *s)
{
	if (*s == 'e' && *(s + 1) == 'c' && *(s + 2) == 'h' &&
	*(s + 3) == 'o' && *(s + 4) == '\0')
		return (1);
	else if (*s == 'c' && *(s + 1) == 'd' && *(s + 2) == '\0')
		return (2);
	else if (*s == 'p' && *(s + 1) == 'w' && *(s + 2) == 'd' &&
	*(s + 3) == '\0')
		return (3);
	else if (*s == 'e' && *(s + 1) == 'x' && *(s + 2) == 'i' &&
	*(s + 3) == 't' && *(s + 4) == '\0')
		return (4);
	else if (*s == 'e' && *(s + 1) == 'n' && *(s + 2) == 'v' &&
	*(s + 3) == '\0')
		return (5);
	else if (*s == 'e' && *(s + 1) == 'x' && *(s + 2) == 'p' &&
	*(s + 3) == 'o' && *(s + 4) == 'r' && *(s + 5) == 't' &&
	*(s + 6) == '\0')
		return (6);
	else if (*s == 'u' && *(s + 1) == 'n' && *(s + 2) == 's' && *(s + 3) == 'e'
	&& *(s + 4) == 't' && *(s + 5) == '\0')
		return (7);
	else if (*s == '/' || (*s == '.' && *(s + 1) == '/') ||
	(*s == '.' && *(s + 1) == '.'))
		return (8);
	return (0);
}

int		array_len(char **cur_commands)
{
	int i;

	i = 0;
	if (cur_commands)
		while (cur_commands[i] != NULL)
			i++;
	return (i);
}

char	*delete_redirects(char *line)
{
	int i;

	i = 0;
	if (line)
	{
		while (line[i])
		{
			if (ft_strchr("<>", line[i]))
			{
				while (line[i] != '\0')
				{
					line[i] = line[i + 1];
					i++;
				}
				i = 0;
			}
			i++;
		}
	}
	return (line);
}

void	right_redirect(t_cmd_list *list, char *s)
{
	if (*(s + 1) == '>')
	{
		list->rr_redir = 1;
		list->theend = 0;
	}
	else if (*(s - 1) != '>')
	{
		list->redir_r = 1;
		list->theend = 0;
	}
}

void	check_redir_pipe(t_cmd_list *list, char *start, char *s)
{
	if (check_scope_for_echo(start, s) == 1)
		return ;
	if (*s == '|')
	{
		list->pipe = 1;
		list->theend = 0;
		*s = '\0';
	}
	else if (*s == '>')
		right_redirect(list, s);
	else if (*s == '<')
	{
		list->redir_l = 1;
		list->theend = 0;
	}
	else
	{
		list->pipe = 0;
		list->redir_r = 0;
		list->redir_l = 0;
		list->rr_redir = 0;
		list->theend = 1;
	}
}
