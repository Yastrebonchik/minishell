/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:58:41 by kcedra            #+#    #+#             */
/*   Updated: 2020/11/11 00:33:48 by cdelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	searching_key_unset(t_env **head, char *key)
{
	t_env	*next;

	if (ft_strncmp(((*head)->next)->key, key, ft_strlen(key) + 1) == 0)
	{
		next = ((*head)->next)->next;
		free(((*head)->next)->key);
		free(((*head)->next)->value);
		free((*head)->next);
		(*head)->next = next;
	}
	if ((*head)->next != NULL)
		*head = (*head)->next;
}

void	unset_error_management(char *cur_command)
{
	if (ft_strchrnum(cur_command, '=') != -1)
	{
		ft_putstr_fd("minishell: export: `", 1);
		ft_putstr_fd(cur_command, 1);
		ft_putendl_fd("': not a valid identifier", 1);
	}
}
