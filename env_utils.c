/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcedra <kcedra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 16:19:55 by kcedra            #+#    #+#             */
/*   Updated: 2020/10/24 17:05:59 by kcedra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env	*ft_envnew(char *content)
{
	t_env	*new_env;
	char	*key;
	char	*value;
	int		value_start;
	
	value_start = ft_strchrnum(content, '=') + 1;
	key = ft_substr(content, 0, value_start - 1);
	value = ft_strdup(&(content[value_start]));
	new_env = (t_env*)malloc(sizeof(t_env));
	if (new_env == NULL || key == NULL || value == NULL)
		return (NULL);
	new_env->key = key;
	new_env->value = value;
	new_env->next = NULL;
	return (new_env);
}

void			env_transform(char **envp, t_env **env)
{
	int		i;
	t_env	*head;
	t_env	*new;

	i = 0;
	head = ft_envnew(envp[i]);
	if (head == NULL)
	{
		ft_putendl_fd("Error: malloc", 1);
		exit(1);
	}
	i++;
	*env = head;
	while (envp[i] != NULL)
	{
		new = ft_envnew(envp[i]);
		head->next = new;
		head = head->next;
		i++;
	}
	head = NULL;
}

void			env_print(t_env *env)
{
	while (env != NULL)
	{
		write(1, env->key, ft_strlen(env->key));
		write(1, "=", 1);
		write(1, env->value, ft_strlen(env->value));
		write(1, "\n", 1);
		env = env->next;
	}
}			