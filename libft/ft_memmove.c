/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 23:54:15 by cdelicia          #+#    #+#             */
/*   Updated: 2020/05/16 20:20:47 by cdelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*to;

	to = (char*)dst;
	if (to == NULL && src == NULL)
		return (NULL);
	if ((char*)src > to)
	{
		while (len > 0)
		{
			*to = *((char*)src);
			to++;
			src++;
			len--;
		}
	}
	else
	{
		while (len > 0)
		{
			*(to + (len - 1)) = *((char*)src + (len - 1));
			len--;
		}
	}
	return (dst);
}
