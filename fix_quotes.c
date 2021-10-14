/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_quotes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 04:07:05 by cdelicia          #+#    #+#             */
/*   Updated: 2020/11/12 06:22:29 by cdelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		strong_quotes(char *content, int i, int key_len)
{
	int j;

	j = 1;
	if (content[i] == '$')
	{
		if (content[i - 1] == '\'' && content[i + key_len] == '\''
		&& content[5] != '\"')
			return (0);
		if (content[5] == '\'')
			while (content[i + key_len] && content[i + key_len] != '$')
			{
				if (content[i + key_len] == '\'')
					return (0);
				i++;
			}
	}
	return (1);
}

char	*delete_quote(char *line, char q, int i)
{
	if (line)
	{
		if (line[i] == q)
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

int		skip_before(int i, t_cmd_list *tmp)
{
	while (tmp->content[i] != '\0' && tmp->content[i] != '\'' &&
	tmp->content[i] != '\"')
		i++;
	return (i);
}

void	init_strong(int *i, int *strong, t_cmd_list *tmp)
{
	*strong = 0;
	if (tmp->content[*i] == '\'' && *strong == 0)
		*strong = 1;
	if (tmp->content[*i] == '\"' && *strong == 0)
		*strong = -1;
	if (ft_strncmp("echo \"\"", tmp->content, 7) == 0)
	{
		tmp->content = delete_quote(tmp->content, '\"', 5);
		tmp->content = delete_quote(tmp->content, '\"', 5);
		*i += 4;
	}
	else if (ft_strncmp("echo \'\'", tmp->content, 7) == 0)
	{
		tmp->content = delete_quote(tmp->content, '\'', 5);
		tmp->content = delete_quote(tmp->content, '\'', 5);
		*i += 4;
	}
}

void	fix_all_quotes(t_cmd_list *tmp)
{
	int i;
	int strong;

	i = 0;
	while (tmp->content[i] != '\0')
	{
		i = skip_before(i, tmp);
		init_strong(&i, &strong, tmp);
		if (tmp->content[i] == '\'' && strong == 1)
		{
			tmp->content = delete_quote(tmp->content, '\'', i);
			i++;
			while (tmp->content[i] != '\0' && tmp->content[i] != '\'')
				i++;
			tmp->content = delete_quote(tmp->content, '\'', i);
		}
		else if (tmp->content[i] == '\"' && strong == -1)
		{
			tmp->content = delete_quote(tmp->content, '\"', i);
			i++;
			while (tmp->content[i] != '\0' && tmp->content[i] != '\"')
				i++;
			tmp->content = delete_quote(tmp->content, '\"', i);
		}
	}
}
