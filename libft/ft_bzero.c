/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:10:14 by cdelicia          #+#    #+#             */
/*   Updated: 2020/10/18 14:10:18 by cdelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char *tmp_dest;

	tmp_dest = (unsigned char *)s;
	while (n--)
	{
		*tmp_dest = '\0';
		tmp_dest++;
	}
}
