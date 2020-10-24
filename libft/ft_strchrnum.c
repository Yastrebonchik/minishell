/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcedra <kcedra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 16:38:50 by kcedra            #+#    #+#             */
/*   Updated: 2020/10/24 16:39:07 by kcedra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strchrnum(const char *s, int c)
{
	int		i;
	char	*ptr;

	ptr = (char*)s;
	i = 0;
	while (ptr[i] != '\0')
	{
		if (ptr[i] == c)
			return (i);
		i++;
	}
	if (c == 0)
		return (i);
	return (0);
}