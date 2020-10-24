/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 17:13:52 by cdelicia          #+#    #+#             */
/*   Updated: 2020/05/15 19:39:30 by cdelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t src_len;
	size_t dst_len;
	size_t total_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	total_len = src_len + dst_len;
	if (total_len + 1 > dstsize)
	{
		if (dst_len >= dstsize)
		{
			total_len = src_len + dstsize;
			src_len = 0;
		}
		else
			src_len = (dstsize - 1) - dst_len;
	}
	while (src_len > 0)
	{
		dst[dst_len++] = *src++;
		src_len--;
	}
	if (dstsize > 0)
		dst[dst_len] = '\0';
	return (total_len);
}
