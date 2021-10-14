/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcedra <kcedra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:00:23 by kcedra            #+#    #+#             */
/*   Updated: 2020/11/20 18:33:13 by kcedra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		clean_redirect_echo(char ***cur_cmds)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*cur_cmds)[1][i] != '>' && (*cur_cmds)[1][i] != '<' &&
	(*cur_cmds)[1][i] != '\0')
		i++;
	tmp = ft_substr((*cur_cmds)[1], 0, i);
	free((*cur_cmds)[1]);
	(*cur_cmds)[1] = tmp;
}

void		clean_redirect(char ***cur_cmds)
{
	int		i;
	char	*tmp;

	i = 0;
	if (ft_strncmp((*cur_cmds)[i], "echo", 5) == 0)
		clean_redirect_echo(cur_cmds);
	else
	{
		while (ft_strncmp((*cur_cmds)[i], ">", 2) != 0 &&
		ft_strncmp((*cur_cmds)[i], ">>", 3) != 0 &&
		ft_strncmp((*cur_cmds)[i], "<", 2) != 0 && (*cur_cmds)[i] != NULL)
			i++;
		while ((*cur_cmds)[i + 2] != NULL)
		{
			tmp = ft_strdup((*cur_cmds)[i + 2]);
			free((*cur_cmds)[i]);
			(*cur_cmds)[i] = tmp;
			i++;
		}
		free((*cur_cmds)[i]);
		(*cur_cmds)[i] = NULL;
		i++;
		free((*cur_cmds)[i]);
		(*cur_cmds)[i] = NULL;
	}
}

void		check_redirect(t_cmd_list *lst, char ***cur_cmds)
{
	int fd;

	if (lst->redir_r == 1 || lst->rr_redir == 1)
	{
		fd = create_file_for_redirect(lst);
		clean_redirect(cur_cmds);
		dup2(fd, 1);
		close(fd);
	}
	if (lst->redir_l == 1)
	{
		fd = open_file_for_read(lst);
		clean_redirect(cur_cmds);
		dup2(fd, 0);
		close(fd);
	}
}

void		execute_command(char **cur_cmds, t_main *data, t_cmd_list *lst)
{
	pid_t	pid;
	int		ret;

	if (lst->pipe == 1)
		execute_command_pipe(cur_cmds, data);
	else
	{
		pid = fork();
		ret = ft_check_command(cur_cmds[0]);
		g_print_flag = (ret != 1 && ret != 3 && ret != 5 && ret != 6) ? 1 : 0;
		if (pid < 0)
			fork_error();
		if (pid == 0)
		{
			fork_signals();
			check_redirect(lst, &cur_cmds);
			if (ret == 1 || ret == 3 || ret == 5 || ret == 6)
				exec_my_functions(ret, cur_cmds, data);
			else
				exec_binaries(ret, data, cur_cmds);
			exit(g_error_flag);
		}
		else
			parent_process(pid, data);
	}
}

void		execute_command_pipe(char **cur_cmds, t_main *data)
{
	pid_t	pid;
	int		ret;

	pipe(data->fd_0);
	pid = fork();
	ret = ft_check_command(cur_cmds[0]);
	g_print_flag = (ret != 1 && ret != 3 && ret != 5 && ret != 6) ? 1 : 0;
	if (pid < 0)
		fork_error();
	if (pid == 0)
	{
		fork_signals();
		dup_fd(data, 0);
		if (ret == 1 || ret == 3 || ret == 5 || ret == 6)
			exec_my_functions(ret, cur_cmds, data);
		else
			exec_binaries(ret, data, cur_cmds);
		exit(g_error_flag);
	}
	else
	{
		dup_fd(data, 1);
		parent_process(pid, data);
	}
}
