/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 16:33:33 by cdelicia          #+#    #+#             */
/*   Updated: 2020/05/15 19:35:41 by cdelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t src_len;
	size_t src_len_copy;

	if (src == NULL)
		return (0);
	src_len = ft_strlen(src);
	src_len_copy = src_len;
	if (dstsize == 0 || dst == NULL)
		return (src_len_copy);
	if (src_len > dstsize - 1)
		src_len = dstsize - 1;
	while (src_len > 0)
	{
		*dst = *src;
		dst++;
		src++;
		src_len--;
		dstsize--;
	}
	if (dstsize != 0)
		*dst = '\0';
	return (src_len_copy);
}
