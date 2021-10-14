/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 01:03:38 by cdelicia          #+#    #+#             */
/*   Updated: 2020/11/11 21:35:11 by cdelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*delete_whitespaces(char *line)
{
	int i;

	if (line)
	{
		while (*line == ' ')
		{
			i = 0;
			while (line[i] != '\0')
			{
				line[i] = line[i + 1];
				i++;
			}
		}
	}
	return (line);
}

int		put_cmds_to_list(char *line, t_main *data)
{
	t_cmd_list	*tmp;
	char		*end;
	char		*start;

	if (line == NULL || *line == '\0')
		return (0);
	end = NULL;
	start = NULL;
	tmp = ft_cmd_lstnew();
	if (!(tmp->content = ft_strdup(line)))
		return (1);
	start = tmp->content;
	end = tmp->content;
	while (*end)
	{
		if (ft_strchr("|<>", *end))
			check_redir_pipe(tmp, start, end);
		end++;
	}
	ft_cmd_lstadd_back(&data->list, tmp);
	return (0);
}

void	split_line_to_list(t_main *main, char *line)
{
	char	**array1;
	char	**array2;
	int		i;
	int		j;

	i = 0;
	g_num = 1;
	if (!(array1 = ft_split_echo(line)))
		return ;
	while (array1[i])
	{
		if (!(array2 = ft_split_set(array1[i], "|")))
			return ;
		j = 0;
		while (array2[j])
		{
			delete_whitespaces(array2[j]);
			if (put_cmds_to_list(array2[j], main))
				return ;
			j++;
		}
		free_all_array_elements(array2, array_len(array2));
		i++;
	}
	free_all_array_elements(array1, array_len(array1));
}
