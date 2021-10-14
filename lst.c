/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 01:02:03 by cdelicia          #+#    #+#             */
/*   Updated: 2020/11/11 00:34:58 by cdelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstclear_env(t_env **lst, void (*del)(void*))
{
	t_env	*list;
	t_env	*next;

	if (lst == NULL)
		return ;
	list = *lst;
	while (list != NULL)
	{
		next = list->next;
		del(list->key);
		del(list->value);
		free(list);
		list = next;
	}
	*lst = NULL;
}

void	ft_lstclear_cmd(t_cmd_list **lst, void (*del)(void*))
{
	t_cmd_list	*list;
	t_cmd_list	*next;

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

void	clear_parced_env_list(t_main *main)
{
	if (main->env)
		ft_lstclear_env(&main->env, free);
	main->env = NULL;
}

void	clear_parced_cmd_list(t_main *main)
{
	if (main->list)
		ft_lstclear_cmd(&main->list, free);
	main->list = NULL;
}

void	ft_cmd_lstadd_back(t_cmd_list **lst, t_cmd_list *new)
{
	t_cmd_list	*tmp;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}
