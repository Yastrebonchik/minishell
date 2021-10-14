/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcedra <kcedra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:16:51 by kcedra            #+#    #+#             */
/*   Updated: 2020/11/20 18:32:11 by kcedra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		exec_binaries(int ret, t_main *data, char **cur_cmds)
{
	t_path	*path;
	char	**envp;

	if (ret == 8)
		execute_binary(&(data->env), cur_cmds);
	else
	{
		path_init(&path, data->env);
		envp = env_to_char(data->env);
		check_and_exec(path, cur_cmds, envp);
		envp_array_clear(envp);
	}
}

void		exec_my_functions(int ret, char **cur_cmds, t_main *data)
{
	if (ret == 1)
		echo(cur_cmds);
	if (ret == 3)
		pwd();
	if (ret == 5)
		env_print(data->env);
	if (ret == 6)
		export(cur_cmds, &(data->env), 1);
}

void		check_and_exec(t_path *path, char **cur_cmds, char **envp)
{
	int		result;
	char	*command;

	result = -1;
	while (path != NULL)
	{
		command = ft_strdup(path->path);
		ft_strlcat(command, "/", ft_strlen(command) + 2);
		ft_strlcat(command, cur_cmds[0], ft_strlen(command) +
		ft_strlen(cur_cmds[0]) + 1);
		result = execve(command, cur_cmds, envp);
		if (result != -1)
			break ;
		path = path->next;
	}
	if (result == -1)
	{
		ft_putstr_fd("minishell: ", 1);
		ft_putstr_fd(cur_cmds[0], 1);
		ft_putendl_fd(": command not found", 1);
		g_error_flag = 127;
	}
}

void		parent_process(pid_t pid, t_main *data)
{
	pid_t	wait_pid;
	int		status;

	wait_pid = waitpid(pid, &status, WUNTRACED);
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == 2)
			reassign_error(130, data);
		if (WTERMSIG(status) == 3)
			reassign_error(131, data);
		if (WTERMSIG(status) == 15)
			reassign_error(143, data);
		write(1, "\n", 1);
	}
	else
		reassign_error(WEXITSTATUS(status), data);
	g_error_flag = 1;
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void		dup_fd(t_main *data, int flag)
{
	if (flag == 0)
	{
		close(data->fd_0[0]);
		dup2(data->fd_0[1], 1);
		close(data->fd_0[1]);
	}
	else
	{
		close(data->fd_0[1]);
		dup2(data->fd_0[0], 0);
		close(data->fd_0[0]);
	}
}
