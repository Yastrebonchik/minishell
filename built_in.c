/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcedra <kcedra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 13:27:34 by kcedra            #+#    #+#             */
/*   Updated: 2020/10/24 16:52:44 by kcedra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			echo(char **cur_command)
{
	int i;

	i = 1;
	while (cur_command[i] != NULL)
	{
		ft_putstr_fd(cur_command[i], 1);
		i++;
	}
}

void			pwd()
{
	char	*cur_dir;
	int		size;

	size = 1;
	cur_dir = (char*)malloc(sizeof(char) * size);
	getcwd(cur_dir, size);
	while (errno == ERANGE)
	{
		errno = 0;
		size++;
		cur_dir = (char*)ft_realloc(cur_dir, size);
		getcwd(cur_dir, size);
	}
	write(1, cur_dir, ft_strlen(cur_dir));
	write(1, "\n", 1);
	free(cur_dir);
}