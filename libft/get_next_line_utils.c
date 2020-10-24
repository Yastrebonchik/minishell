/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 17:01:37 by cdelicia          #+#    #+#             */
/*   Updated: 2020/08/28 15:34:41 by cdelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		gnl_strlen(char *s)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

char	*gnl_strchr(char *s, char c)
{
	int	s_len;

	s_len = gnl_strlen(s);
	while (s_len >= 0)
	{
		if (*s == c)
			return (s);
		s++;
		s_len--;
	}
	return (NULL);
}

char	*gnl_strdup(char *s1)
{
	char	*ptr;
	int		dstsize;

	dstsize = gnl_strlen(s1) + 1;
	ptr = (char*)malloc(dstsize);
	if (ptr != NULL)
		gnl_strlcpy(ptr, s1, dstsize);
	return (ptr);
}

int		gnl_strlcpy(char *dst, char *src, int dstsize)
{
	int	src_len;
	int	src_len_copy;

	if (src == NULL)
		return (0);
	src_len = gnl_strlen(src);
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

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*join;
	char	*start;
	int		i;

	i = 0;
	if (!s1)
		return (gnl_strdup(s2));
	join = (char*)malloc(gnl_strlen(s1) + gnl_strlen(s2) + 1);
	if (join == NULL)
		return (NULL);
	start = join;
	while (s1[i] != '\0')
	{
		*join++ = s1[i];
		i++;
	}
	free(s1);
	s1 = NULL;
	while (*s2 != '\0')
		*join++ = *s2++;
	*join = '\0';
	return (start);
}
