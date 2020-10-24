/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 22:52:46 by cdelicia          #+#    #+#             */
/*   Updated: 2020/05/22 13:48:42 by cdelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*to;
	const char	*from;

	to = (char*)dst;
	from = (char*)src;
	while (n > 0)
	{
		*to = *from;
		if (*to == (char)c)
			return ((void*)to + 1);
		to++;
		from++;
		n--;
	}
	return (NULL);
}
