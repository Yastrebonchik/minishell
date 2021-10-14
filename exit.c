/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcedra <kcedra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 00:37:55 by cdelicia          #+#    #+#             */
/*   Updated: 2020/11/20 18:30:02 by kcedra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_return_env_var(int error, t_main *data)
{
	t_env	*tmp;

	tmp = data->env;
	while (tmp)
	{
		if (ft_strncmp(tmp->key, "?", 1) == 0 &&
		ft_strncmp(tmp->key, "?", ft_strlen(tmp->key)) == 0)
		{
			free(tmp->value);
			tmp->value = ft_itoa(error);
			return ;
		}
		tmp = tmp->next;
	}
}

void	syntax_error(t_main *data)
{
	ft_putstr_fd("Syntax error\n", 2);
	change_return_env_var(258, data);
}

void	envp_array_clear(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i] != NULL)
		free(envp[i]);
	free(envp);
}

void	reassign_error(int error, t_main *data)
{
	free(data->env->value);
	data->env->value = ft_itoa(error);
}

void	fork_error(void)
{
	char	*str;

	signal(SIGINT, sigint);
	signal(SIGQUIT, sigquit);
	reassign_error(errno, g_main_ptr);
	str = strerror(errno);
	ft_putstr_fd("minishell: ", 2);
	ft_putendl_fd(str, 2);
	return ;
}
