/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcedra <kcedra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 01:21:19 by cdelicia          #+#    #+#             */
/*   Updated: 2020/11/20 16:08:08 by kcedra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		error_syntax_check(char **split, int i)
{
	if (!(split[i + 1]))
	{
		syntax_error(g_main_ptr);
		return (-1);
	}
	if (split[i + 2])
	{
		syntax_error(g_main_ptr);
		return (-1);
	}
	return (0);
}

int		create_file_for_redirect(t_cmd_list *lst)
{
	int		fd;
	char	**split;
	int		i;

	i = 0;
	split = ft_split(lst->content, ' ');
	while (split[i] != NULL)
	{
		if (ft_strncmp(split[i], ">", 1) == 0 ||
		ft_strncmp(split[i], ">>", 2) == 0)
			break ;
		i++;
	}
	if (error_syntax_check(split, i) == -1)
		exit(254);
	if (lst->rr_redir)
		fd = open(split[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0666);
	else if (lst->redir_r)
		fd = open(split[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	else
		fd = -1;
	free_all_array_elements(split, array_len(split));
	return (fd);
}

int		open_file_for_read(t_cmd_list *lst)
{
	int		fd;
	char	**split;
	int		i;

	i = 0;
	split = ft_split(lst->content, ' ');
	while (split[i] != NULL)
	{
		if (ft_strncmp(split[i], "<", 1) == 0)
			break ;
		i++;
	}
	if (error_syntax_check(split, i) == -1)
		exit(1);
	fd = open(split[i + 1], O_RDONLY);
	free_all_array_elements(split, array_len(split));
	return (fd);
}
