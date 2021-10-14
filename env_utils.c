/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcedra <kcedra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 16:19:55 by kcedra            #+#    #+#             */
/*   Updated: 2020/11/20 18:22:17 by kcedra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env		*ft_envnew(char *content)
{
	t_env	*new_env;
	char	*key;
	char	*value;
	int		value_start;

	value_start = ft_strchrnum(content, '=') + 1;
	key = ft_substr(content, 0, value_start - 1);
	value = ft_strdup(&(content[value_start]));
	new_env = (t_env *)malloc(sizeof(t_env));
	if (new_env == NULL || key == NULL || value == NULL)
		return (NULL);
	new_env->key = key;
	new_env->value = value;
	new_env->next = NULL;
	return (new_env);
}

void		env_init(char **envp, t_env **env)
{
	int		i;
	t_env	*head;
	t_env	*new;

	head = ft_envnew("?=0");
	if (head == NULL)
	{
		ft_putendl_fd("Error: malloc", 1);
		exit(1);
	}
	head->visible = 0;
	*env = head;
	i = 0;
	while (envp[i] != NULL)
	{
		new = ft_envnew(envp[i]);
		head->next = new;
		head = head->next;
		head->visible = 1;
		i++;
	}
	head = NULL;
}

void		env_print(t_env *env)
{
	int i;

	i = 0;
	while (env != NULL)
	{
		if (env->visible == 1)
		{
			i = 0;
			if (env->key)
				i = ft_strlen(env->key);
			write(1, env->key, i);
			write(1, "=", 1);
			i = 0;
			if (env->value)
				i = ft_strlen(env->value);
			write(1, env->value, i);
			write(1, "\n", 1);
		}
		env = env->next;
	}
}

static void	envp_elem_transform(t_env **head, char ***envp, int *counter)
{
	int	len;

	len = ft_strlen((*head)->key) + ft_strlen((*head)->value) + 2;
	(*envp)[*counter] = (char*)malloc(sizeof(char) * len);
	ft_strlcpy((*envp)[*counter], (*head)->key, ft_strlen((*head)->key) + 1);
	ft_strlcpy(&((*envp)[*counter][ft_strlen((*head)->key)]), "=", 2);
	ft_strlcpy(&((*envp)[*counter][ft_strlen((*head)->key) + 1]),
	(*head)->value, ft_strlen((*head)->value) + 1);
	counter++;
}

char		**env_to_char(t_env *env)
{
	char	**envp;
	int		counter;
	t_env	*head;

	head = env;
	counter = 1;
	while (head->next != NULL)
	{
		counter++;
		head = head->next;
	}
	head = env;
	envp = (char**)malloc(sizeof(char*) * (counter + 1));
	counter = 0;
	while (head->next != NULL)
	{
		envp_elem_transform(&head, &envp, &counter);
		head = head->next;
	}
	envp_elem_transform(&head, &envp, &counter);
	counter++;
	envp[counter] = NULL;
	return (envp);
}
