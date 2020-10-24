/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 18:34:07 by cdelicia          #+#    #+#             */
/*   Updated: 2020/05/08 18:43:27 by cdelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	s_len;

	s_len = (int)ft_strlen(s);
	s = s + s_len;
	while (s_len >= 0)
	{
		if (*((char*)s) == (char)c)
			return ((char*)s);
		s--;
		s_len--;
	}
	return (NULL);
}
