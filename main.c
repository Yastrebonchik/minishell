/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcedra <kcedra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 00:07:59 by cdelicia          #+#    #+#             */
/*   Updated: 2020/10/24 17:06:07 by kcedra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	exec_command()
// {

// }

int				ft_check_command(char *s)
{
	if (*s == 'e' && *(s + 1) == 'c' && *(s + 2) == 'h' && *(s + 3) == 'o' && (*(s + 4) == '\13' || *(s + 4) == '\0'))
		return (1);
	else if (*s == 'c' && *(s + 1) == 'd' && (*(s + 2) == '\13' || *(s + 2) == '\0'))
		return (2);
	else if (*s == 'p' && *(s + 1) == 'w' && *(s + 2) == 'd' && (*(s + 3) == '\13' || *(s + 3) == '\0'))
		return (3);
	else if (*s == 'e' && *(s + 1) == 'x' && *(s + 2) == 'i' && *(s + 3) == 't' && (*(s + 4) == '\13' || *(s + 4) == '\0'))
		return (4);
	else if (*s == 'e' && *(s + 1) == 'n' && *(s + 2) == 'v' && (*(s + 3) == '\13' || *(s + 3) == '\0'))
		return (5);
	return (0);
}

int		main(int argc, char **argv, char **envp)
{
	t_main			main;
	t_command_list	list;
	t_env			*env;
	char			**cur_command;
	int				ret;

	if (argc != 1)
		exit(1);
	argv[0][0] = 'e';
	env_transform(envp, &env);
	ft_bzero(&main, sizeof(main));
	list.str = ft_strdup("env");
	while (1)
	{
		//ft_parcing(&main);
		cur_command = ft_split(list.str, ' ');
		ret = ft_check_command(cur_command[0]);
		if (ret == 1)
			echo(cur_command);
		if (ret == 3)
			pwd();
		if (ret == 4)
		{
			printf("exit\n");
			free(list.str);
			exit(0);
		}
		if (ret == 5)
			env_print(env);
		list.str = ft_strdup("exit");
		//ft_clear_parced_data(&main.parce_list);
	}
	return (0);
}

// int		ft_parcing(t_main *data)
// {
// 	char			*line;
// 	int				ret;

// 	if ((line = getcwd(NULL, 0)) == NULL)
// 		return (-1);
// 	if ((ret = get_next_line(0, &line)) == 0 && !(ft_strlen(line)))
// 		exit(0);
// 	else if (ret == -1)
// 		exit(1);
// 	else
// 		read_line(line, &data->parce_list, data);
// 	free(line);
// 	return (0);
// }
