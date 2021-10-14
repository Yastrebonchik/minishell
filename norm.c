/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 01:02:03 by cdelicia          #+#    #+#             */
/*   Updated: 2020/11/11 00:34:58 by cdelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_strlen_key(char *s)
{
	int i;

	i = 1;
	if (s)
	{
		while (*s)
		{
			if (*s == ' ' || *s == '$' || *s == ';' ||
			*s == '\"' || *s == '\0' || *s == '\'')
				return (i);
			s++;
			i++;
		}
	}
	return (i);
}

int			syntax_error_int(t_main *data)
{
	ft_putstr_fd("Syntax error\n", 2);
	change_return_env_var(258, data);
	return (1);
}

int			check_syntax(char *line, t_main *main)
{
	int len;

	len = ft_strlen(line);
	if (check_pipe(line, len))
		return (syntax_error_int(main));
	if (check_redirects(line, len))
		return (syntax_error_int(main));
	if (check_quotes_1(line))
		return (syntax_error_int(main));
	if (check_quotes_2(line))
		return (syntax_error_int(main));
	return (0);
}

char		*delete_backslash(char *line, int i)
{
	if (line)
	{
		if (line[i] == '\\')
		{
			while (line[i] != '\0')
			{
				line[i] = line[i + 1];
				i++;
			}
		}
	}
	return (line);
}

void		delete_all_backslash(t_cmd_list *tmp)
{
	int i;

	i = 0;
	while (tmp->content[i])
	{
		if (tmp->content[i] == '\\' && tmp->content[i + 1] == '\0')
			syntax_error_int(g_main_ptr);
		if (tmp->content[i] == '\\' && tmp->content[i + 1] && \
		(tmp->content[i + 1] == '$' || tmp->content[i + 1] == '\'' \
		|| tmp->content[i + 1] == '\"'))
			tmp->content = delete_backslash(tmp->content, i);
		else if (tmp->content[i] == '\\' && tmp->content[i + 1] && i > 1 \
		&& tmp->content[i - 1] != '\"' && tmp->content[i - 1] != '\'')
			tmp->content = delete_backslash(tmp->content, i);
		i++;
	}
}
