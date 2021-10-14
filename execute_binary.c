/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_binary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcedra <kcedra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:14:54 by kcedra            #+#    #+#             */
/*   Updated: 2020/11/21 13:22:42 by kcedra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_binary(t_env **env, char **cur_cmds)
{
	char	**envp;
	int		result;

	envp = env_to_char(*env);
	result = execve(cur_cmds[0], cur_cmds, envp);
	if (result == -1)
	{
		ft_putstr_fd("minishell: ", 1);
		ft_putstr_fd(cur_cmds[0], 1);
		ft_putstr_fd(": ", 1);
		ft_putendl_fd(strerror(errno), 1);
		g_error_flag = 127;
		if (errno == 13)
			g_error_flag = 126;
	}
	envp_array_clear(envp);
}
