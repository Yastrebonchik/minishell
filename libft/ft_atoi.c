/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 22:39:06 by cdelicia          #+#    #+#             */
/*   Updated: 2020/10/05 01:49:33 by cdelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	if (c == '\r' || c == '\f' || c == '\v')
		return (1);
	return (0);
}

int	ft_strlen_plus(const char *s)
{
	int count;

	count = 0;
	while (*s != '\0')
	{
		if (ft_isdigit(*s) != 1)
			return (0);
		else
			count++;
		s++;
	}
	return (count);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			n;

	i = 0;
	n = 0;
	while (ft_isspace((char)str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
		return (-1);
	if (ft_strlen_plus(str + i) > 10)
		return (10000);
	while (ft_isdigit((char)str[i]) == 1)
	{
		n = 10 * n + (str[i++] - '0');
		if (n >= 10000)
			return (10000);
	}
	return (n);
}
