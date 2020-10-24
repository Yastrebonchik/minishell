/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 01:01:50 by cdelicia          #+#    #+#             */
/*   Updated: 2020/05/14 14:51:04 by cdelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_reverse(char *s)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s) - 1;
	while (i < j)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		i++;
		j--;
	}
}

int		ft_formalloc(int n)
{
	int	counter;
	int	sign;

	sign = 0;
	if (n < 0)
		sign = 1;
	if (n == 0)
		return (2);
	counter = 0;
	while (n != 0)
	{
		n = n / 10;
		counter++;
	}
	return (counter + sign + 1);
}

char	*ft_itoa(int n)
{
	int				i;
	unsigned int	un;
	char			*s;

	i = 0;
	s = (char*)malloc(ft_formalloc(n));
	if (s == NULL)
		return (NULL);
	if (n == 0)
		s[i++] = '0';
	if (n < 0)
		un = -n;
	else
		un = n;
	while (un > 0)
	{
		s[i++] = un % 10 + '0';
		un = un / 10;
	}
	if (n < 0)
		s[i++] = '-';
	s[i] = '\0';
	ft_reverse(s);
	return (s);
}
