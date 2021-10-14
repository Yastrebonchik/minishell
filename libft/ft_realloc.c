/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcedra <kcedra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:40:29 by kcedra            #+#    #+#             */
/*   Updated: 2020/10/29 16:16:26 by kcedra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *str, size_t size)
{
	void	*new;

	new = ft_calloc(size, size);
	ft_memcpy(new, str, ft_strlen(str));
	free(str);
	return (new);
}
