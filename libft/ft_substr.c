/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 21:23:01 by cdelicia          #+#    #+#             */
/*   Updated: 2020/05/19 20:51:33 by cdelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < start)
	{
		ptr = (char*)malloc(1);
		if (ptr != NULL)
			ft_strlcpy(ptr, "", 1);
		return (ptr);
	}
	if (len + start > s_len)
		len = s_len - start;
	ptr = (char*)malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	s = s + start;
	if (len > 0)
		ft_strlcpy(ptr, s, len + 1);
	if (len == 0)
		*ptr = '\0';
	return (ptr);
}
