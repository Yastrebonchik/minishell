/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 21:07:50 by cdelicia          #+#    #+#             */
/*   Updated: 2020/05/10 23:39:48 by cdelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		dstsize;

	dstsize = ft_strlen(s1) + 1;
	ptr = (char*)malloc(dstsize);
	if (ptr != NULL)
		ft_strlcpy(ptr, s1, dstsize);
	return (ptr);
}
