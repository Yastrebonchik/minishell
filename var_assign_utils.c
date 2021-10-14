/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_assign_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcedra <kcedra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:50:21 by kcedra            #+#    #+#             */
/*   Updated: 2020/11/20 17:44:30 by kcedra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			check_var_assign(char ***s)
{
	int		i;

	i = 0;
	while ((*s)[i] != NULL)
	{
		if (ft_strchrnum((*s)[i], '=') < 1)
		{
			free((*s)[0]);
			(*s)[0] = ft_strdup((*s)[i]);
			return (0);
		}
		i++;
	}
	return (1);
}

void		assign_value(char **cur_command, t_env **env, int i)
{
	t_env	*head;
	int		value_start;
	char	*key;

	while (cur_command[i] != NULL)
	{
		head = *env;
		value_start = ft_strchrnum(cur_command[i], '=') + 1;
		key = ft_substr(cur_command[i], 0, value_start - 1);
		while (head->next != NULL)
		{
			head = head->next;
			if (ft_strncmp(head->key, key, ft_strlen(key) + 1) == 0)
			{
				head = *env;
				searching_key_export(&head, cur_command[i]);
			}
		}
		i++;
	}
	free(key);
}
