/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 20:29:26 by cdelicia          #+#    #+#             */
/*   Updated: 2020/05/22 13:04:22 by cdelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*value;
	t_list	*start;
	t_list	*back;

	if (lst == NULL)
		return (NULL);
	start = NULL;
	while (lst != NULL)
	{
		if ((value = f(lst->content)) == NULL)
			del(value);
		back = ft_lstnew(value);
		if (back == NULL)
			return (NULL);
		ft_lstadd_back(&start, back);
		lst = lst->next;
	}
	return (start);
}
