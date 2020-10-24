/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 18:45:04 by cdelicia          #+#    #+#             */
/*   Updated: 2020/05/14 15:25:46 by cdelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	haystack_len;
	size_t	i;
	size_t	j;

	i = 0;
	needle_len = ft_strlen(needle);
	haystack_len = ft_strlen(haystack);
	if (needle_len == 0)
		return ((char*)haystack);
	if (haystack_len > len)
		haystack_len = len;
	while (needle_len + i <= haystack_len)
	{
		j = 0;
		while (needle[j] == haystack[i + j])
		{
			if (j == needle_len - 1)
				return ((char*)(haystack + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
