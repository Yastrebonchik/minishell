/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 20:11:44 by cdelicia          #+#    #+#             */
/*   Updated: 2020/05/22 12:55:04 by cdelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*list;
	t_list	*next;

	if (lst == NULL)
		return ;
	list = *lst;
	while (list != NULL)
	{
		next = list->next;
		del(list->content);
		free(list);
		list = next;
	}
	*lst = NULL;
}
