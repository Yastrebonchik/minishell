/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 21:57:52 by cdelicia          #+#    #+#             */
/*   Updated: 2020/05/15 19:39:31 by cdelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	char	*ptr;
	char	*start;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = (char*)malloc(s1_len + s2_len + 1);
	if (ptr == NULL)
		return (NULL);
	start = ptr;
	while (*(char*)s1 != '\0')
	{
		*ptr = *s1++;
		ptr++;
	}
	while (*(char*)s2 != '\0')
	{
		*ptr = *s2++;
		ptr++;
	}
	*ptr = '\0';
	return (start);
}
