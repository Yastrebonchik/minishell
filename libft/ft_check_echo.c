/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 03:37:51 by cdelicia          #+#    #+#             */
/*   Updated: 2020/11/11 20:33:28 by cdelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_quotes(char *line, char *end)
{
	int i;

	i = 0;
	while (line < end)
	{
		if (*line == '\"' || *line == '\'')
		{
			line++;
			i = 1;
			while (line < end)
			{
				if (*line == '\"' || *line == '\'')
					return (0);
				line++;
			}
		}
		line++;
	}
	if (i == 1)
		return (1);
	return (0);
}

static char		*check_yes_or_no(char *line, char *end)
{
	while (line < end)
	{
		if (*line == 'e')
			if (*(line + 1) == 'c')
				if (*(line + 2) == 'h')
					if (*(line + 3) == 'o')
						return (line + 4);
		line++;
	}
	return (NULL);
}

int				check_scope_for_echo(char *start, char *line)
{
	char *echo;

	echo = NULL;
	if ((echo = check_yes_or_no(start, line)) != NULL)
		if (check_quotes(echo, line) == 1)
			return (1);
	return (0);
}
