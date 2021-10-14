/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcedra <kcedra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 01:06:44 by cdelicia          #+#    #+#             */
/*   Updated: 2020/11/20 14:03:25 by kcedra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		initialization_all(t_main *main)
{
	g_main_ptr = main;
	g_num = 1;
	g_print_flag = 0;
	g_error_flag = 0;
	ft_bzero(main, sizeof(*main));
	ft_bzero(main->separator, 4);
	main->save_0 = dup(0);
	main->save_1 = dup(1);
}

t_cmd_list	*ft_cmd_lstnew(void)
{
	t_cmd_list *tmp;

	tmp = (t_cmd_list *)malloc(sizeof(t_cmd_list));
	tmp->number = g_num++;
	tmp->pipe = 0;
	tmp->redir_r = 0;
	tmp->rr_redir = 0;
	tmp->redir_l = 0;
	tmp->theend = 0;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}
