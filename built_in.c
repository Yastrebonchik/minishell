/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcedra <kcedra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 13:27:34 by kcedra            #+#    #+#             */
/*   Updated: 2020/11/20 16:56:42 by kcedra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		echo(char **cur_command)
{
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	if (cur_command[1][0] == '-' && cur_command[1][1] == 'n' &&
	(cur_command[1][2] == ' ' || cur_command[1][2] == '\0'))
	{
		i += 2;
		if (cur_command[1][2] == ' ')
			i++;
		flag = 1;
	}
	while (cur_command[1][i] != '\0')
		ft_putchar_fd(cur_command[1][i++], 1);
	if (flag == 0)
		write(1, "\n", 1);
}

void		pwd(void)
{
	char	*cur_dir;

	cur_dir = getcwd(NULL, 0);
	write(1, cur_dir, ft_strlen(cur_dir));
	write(1, "\n", 1);
	free(cur_dir);
}

void		cd(char **cur_command, t_env **env)
{
	int		flag;
	char	*curdir;
	char	*oldpwd;
	t_env	*head;

	head = *env;
	oldpwd = getcwd(NULL, 0);
	curdir = cur_command[1];
	if (chdir(curdir) == -1)
	{
		ft_putstr_fd("minishell: cd: ", 1);
		ft_putstr_fd(curdir, 1);
		if (curdir != NULL)
			ft_putstr_fd(": ", 1);
		ft_putendl_fd(strerror(errno), 1);
		free((*env)->value);
		(*env)->value = ft_itoa(1);
		g_error_flag = 1;
		free(oldpwd);
	}
	else
	{
		flag = reassign_wd(curdir, oldpwd, &head);
		create_oldwd(flag, oldpwd, &head);
	}
}

void		export(char **cur_command, t_env **env, int i)
{
	t_env	*head;

	export_print(*env, cur_command[i], 1);
	while (cur_command[i] != NULL)
	{
		head = *env;
		searching_key_export(&head, cur_command[i]);
		i++;
	}
}

void		unset(char **cur_command, t_env **env)
{
	int		i;
	char	*key;
	t_env	*head;

	i = 1;
	while (cur_command[i] != NULL)
	{
		head = *env;
		key = ft_strdup(cur_command[i]);
		if (ft_strncmp(head->key, key, ft_strlen(key) + 1) == 0)
		{
			*env = head->next;
			free(head->key);
			free(head->value);
			free(head);
		}
		while (head->next != NULL)
			searching_key_unset(&head, key);
		unset_error_management(cur_command[i]);
		free(key);
		i++;
	}
}
