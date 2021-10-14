/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcedra <kcedra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 15:15:27 by kcedra            #+#    #+#             */
/*   Updated: 2020/11/20 17:42:19 by kcedra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		put_info_dir(char **dir, t_env **head)
{
	(*head)->value = ft_realloc((*head)->value, ft_strlen(*dir) + 1);
	ft_strlcpy((*head)->value, *dir, ft_strlen(*dir) + 1);
	free(*dir);
}

int			reassign_wd(char *curdir, char *oldpwd, t_env **head)
{
	int	flag;

	flag = 0;
	curdir = getcwd(NULL, 0);
	if (ft_strncmp(((*head)->key), "PWD", 4) == 0)
		put_info_dir(&curdir, &(*head));
	if (ft_strncmp(((*head)->key), "OLDPWD", 7) == 0)
	{
		flag = 1;
		put_info_dir(&oldpwd, &(*head));
	}
	while ((*head)->next != NULL)
	{
		(*head) = (*head)->next;
		if (ft_strncmp(((*head)->key), "PWD", 4) == 0)
			put_info_dir(&curdir, &(*head));
		if (ft_strncmp(((*head)->key), "OLDPWD", 7) == 0)
		{
			flag = 1;
			put_info_dir(&oldpwd, &(*head));
		}
	}
	return (flag);
}

void		create_oldwd(int flag, char *oldpwd, t_env **head)
{
	t_env	*new;

	if (flag == 0)
	{
		new = ft_envnew("OLDPWD=new");
		(*head)->next = new;
		(*head) = (*head)->next;
		put_info_dir(&oldpwd, &(*head));
	}
}
