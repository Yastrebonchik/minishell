/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 01:02:03 by cdelicia          #+#    #+#             */
/*   Updated: 2020/11/11 00:34:58 by cdelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_pipe(char *line, int len)
{
	int i;

	i = 0;
	if (line[0] == '|' || line[len - 1] == '|')
		return (1);
	while (line[i])
	{
		if (line[i] == '|' && i != 0)
		{
			if (line[i + 1] == ';')
				return (1);
			if (line[i + 1] == '|')
				return (1);
		}
		i++;
	}
	return (0);
}

int		check_redirects(char *line, int len)
{
	if (line[0] == '>' || line[len - 1] == '>')
		return (1);
	if (line[0] == '<' || line[len - 1] == '<')
		return (1);
	return (0);
}

int		not_echo(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'e')
			if (line[i + 1] == 'c')
				if (line[i + 2] == 'h')
					if (line[i + 3] == 'o')
						return (0);
		i++;
	}
	return (1);
}

int		check_quotes_1(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (ft_strncmp(line, "echo \"", 6) == 0)
			if (line[6] == '\0')
				return (1);
		if (line[i] == '\"' && not_echo(line))
		{
			i++;
			while (line[i])
			{
				if (line[i] == '\"')
					return (0);
				i++;
			}
			return (1);
		}
		i++;
	}
	return (0);
}

int		check_quotes_2(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (ft_strncmp(line, "echo \'", 6) == 0)
			if (line[6] == '\0')
				return (1);
		if (line[i] == '\'' && not_echo(line))
		{
			i++;
			while (line[i])
			{
				if (line[i] == '\'')
					return (0);
				i++;
			}
			return (1);
		}
		i++;
	}
	return (0);
}
