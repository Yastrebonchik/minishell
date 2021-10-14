/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcedra <kcedra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:43:19 by cdelicia          #+#    #+#             */
/*   Updated: 2020/11/21 13:44:09 by kcedra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	start_executing(t_main *data, char **cur_cmds, t_cmd_list *tmp)
{
	int	ret;
	int	ext;

	ret = ft_check_command(cur_cmds[0]);
	if (check_var_assign(&cur_cmds) == 1)
		ret = 9;
	if (ret == 2)
		cd(cur_cmds, &(data->env));
	else if (ret == 6 && cur_cmds[1] != NULL)
		export(cur_cmds, &(data->env), 1);
	else if (ret == 7)
		unset(cur_cmds, &(data->env));
	else if (ret == 4)
	{
		ext = cur_cmds[1] ? ft_atoi(cur_cmds[1]) : 0;
		free_all_array_elements(cur_cmds, array_len(cur_cmds));
		exit(ext);
	}
	else if (ret == 9)
		assign_value(cur_cmds, &(data->env), 0);
	else
		execute_command(cur_cmds, data, tmp);
	if (g_error_flag == 0)
		reassign_error(0, data);
	g_error_flag = 0;
}

char	**put_command_to_array(t_cmd_list *tmp)
{
	char	**cur_cmds;

	cur_cmds = NULL;
	if (ft_strncmp("echo", tmp->content, 4) == 0)
	{
		cur_cmds = (char **)malloc(sizeof(char*) * 3);
		cur_cmds[0] = ft_strdup("echo");
		cur_cmds[1] = ft_strdup("\0");
		if (tmp->content[4] != '\0' && (tmp->content + 5))
		{
			free(cur_cmds[1]);
			cur_cmds[1] = ft_strdup(tmp->content + 5);
		}
		cur_cmds[2] = NULL;
	}
	else if (!(cur_cmds = ft_split(tmp->content, ' ')))
		return (NULL);
	return (cur_cmds);
}

int		read_line(char *line, t_main *data)
{
	char		**cur_cmds;
	t_cmd_list	*tmp;

	split_line_to_list(data, line);
	tmp = data->list;
	while (tmp)
	{
		fix_content(tmp, data->env, data->env);
		fix_all_quotes(tmp);
		while (tmp != NULL)
		{
			cur_cmds = put_command_to_array(tmp);
			start_executing(data, cur_cmds, tmp);
			if (tmp->pipe != 1 && tmp->prev && tmp->prev->pipe == 1)
			{
				data->fd_0[0] = data->save_0;
				data->fd_0[1] = data->save_1;
				dup2(data->fd_0[0], 0);
				dup2(data->fd_0[1], 1);
			}
			free_all_array_elements(cur_cmds, array_len(cur_cmds));
			tmp = tmp->next;
		}
	}
	return (0);
}

int		ft_parcing(t_main *data)
{
	char	*line;
	int		ret;

	if (!(line = getcwd(NULL, 0)))
		return (-1);
	print_input_calling(line);
	if ((ret = get_next_line(0, &line)) == 0 && !(ft_strlen(line)))
		exit(0);
	else if (ret == -1)
		exit(1);
	else
	{
		if (check_syntax(line, data))
		{
			free(line);
			return (0);
		}
		read_line(line, data);
	}
	free(line);
	return (0);
}
