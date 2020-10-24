/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:10:23 by cdelicia          #+#    #+#             */
/*   Updated: 2020/10/18 14:10:27 by cdelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *tmp_dest;
	unsigned char tmp_c;

	tmp_dest = (unsigned char *)b;
	tmp_c = (unsigned char)c;
	while (len--)
	{
		*tmp_dest = tmp_c;
		tmp_dest++;
	}
	return (b);
}
