/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcedra <kcedra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 00:07:59 by cdelicia          #+#    #+#             */
/*   Updated: 2020/11/20 14:47:39 by kcedra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_input_calling(char *s)
{
	signal(SIGINT, sigint);
	signal(SIGQUIT, sigquit);
	ft_putstr_fd("\033[32m", 1);
	ft_putstr_fd("minishell:", 1);
	ft_putstr_fd(s, 1);
	ft_putstr_fd(" ", 1);
	ft_putstr_fd(">$", 1);
	ft_putstr_fd("\033[0m", 1);
	ft_putstr_fd(" ", 1);
	free(s);
}

int		main(int argc, char **argv, char **envp)
{
	t_main	main;

	if (argc != 1 && argv[0])
	{
		ft_putstr_fd("Wrong number of arguments\n", 2);
		return (1);
	}
	initialization_all(&main);
	env_init(envp, &main.env);
	while (1)
	{
		ft_parcing(&main);
		clear_parced_cmd_list(&main);
	}
	clear_parced_env_list(&main);
	return (0);
}
