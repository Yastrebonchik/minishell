/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 19:54:33 by cdelicia          #+#    #+#             */
/*   Updated: 2020/05/08 20:10:05 by cdelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*((char*)s1) == *((char*)s2) && n > 0)
	{
		if (*((char*)s1) == '\0')
			return (0);
		s1++;
		s2++;
		n--;
		if (n == 0)
			return (0);
	}
	return (*((unsigned char*)s1) - *((unsigned char*)s2));
}
