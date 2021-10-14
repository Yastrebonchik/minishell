/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcedra <kcedra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:21:06 by kcedra            #+#    #+#             */
/*   Updated: 2020/11/20 18:15:58 by kcedra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		create_new_elem(t_env **head, char *key, char *value,
int value_start)
{
	t_env	*new;

	new = ft_envnew("OLDPWD=new");
	(*head)->next = new;
	*head = (*head)->next;
	(*head)->key = ft_realloc((*head)->key, ft_strlen(key) + 1);
	ft_strlcpy((*head)->key, key, ft_strlen(key) + 1);
	if (value_start == 0)
	{
		(*head)->value = ft_realloc((*head)->value, 1);
		(*head)->value[0] = '\0';
		(*head)->visible = 0;
	}
	else
	{
		(*head)->value = ft_realloc((*head)->value, ft_strlen(value) + 1);
		ft_strlcpy((*head)->value, value, ft_strlen(value) + 1);
		(*head)->visible = 1;
	}
}

static void	reassign_value(t_env **head, int *flag, char *value,
char *cur_command)
{
	*flag = 1;
	if (ft_strchrnum(cur_command, '=') != -1)
	{
		(*head)->value = ft_realloc((*head)->value, ft_strlen(value));
		ft_strlcpy((*head)->value, value, ft_strlen(value) + 1);
		(*head)->visible = 1;
	}
}

static void	export_error_management(char *cur_command, int *flag)
{
	ft_putstr_fd("minishell: export: `", 1);
	ft_putstr_fd(cur_command, 1);
	ft_putendl_fd("': not a valid identifier", 1);
	*flag = 1;
}

void		searching_key_export(t_env **head, char *cur_command)
{
	int		value_start;
	char	*key;
	char	*value;
	int		flag;

	flag = 0;
	value_start = ft_strchrnum(cur_command, '=') + 1;
	key = ft_substr(cur_command, 0, value_start - 1);
	value = ft_strdup(&(cur_command[value_start]));
	if (ft_strncmp((*head)->key, key, ft_strlen(key) + 1) == 0)
		reassign_value(&(*head), &flag, value, cur_command);
	while ((*head)->next != NULL)
	{
		*head = (*head)->next;
		if (ft_strncmp((*head)->key, key, ft_strlen(key) + 1) == 0)
			reassign_value(head, &flag, value, cur_command);
	}
	if (cur_command[0] == '=')
		export_error_management(cur_command, &flag);
	if (flag == 0 && key[0] != '\0')
		create_new_elem(head, key, value, value_start);
	free(key);
	free(value);
}

void		export_print(t_env *env, char *cur_command, int fd)
{
	if (cur_command == NULL)
	{
		while (env != NULL)
		{
			if (ft_strncmp("_", env->key, 2) != 0 &&
			ft_strncmp("?", env->key, 2))
			{
				ft_putstr_fd("declare -x ", fd);
				ft_putstr_fd(env->key, fd);
				if (env->visible == 1)
				{
					ft_putstr_fd("=\"", fd);
					ft_putstr_fd(env->value, fd);
					ft_putchar_fd('\"', fd);
				}
				ft_putchar_fd('\n', 1);
			}
			env = env->next;
		}
	}
}
