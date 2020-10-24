/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 18:33:01 by cdelicia          #+#    #+#             */
/*   Updated: 2020/05/08 18:41:12 by cdelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	s_len;

	s_len = (int)ft_strlen(s);
	while (s_len >= 0)
	{
		if (*((char*)s) == (char)c)
			return ((char*)s);
		s++;
		s_len--;
	}
	return (NULL);
}
