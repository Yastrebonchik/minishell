/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcedra <kcedra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 14:44:30 by kcedra            #+#    #+#             */
/*   Updated: 2020/11/21 13:55:40 by kcedra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigint(int sig)
{
	char	*line;

	sig = 0;
	if (!(line = getcwd(NULL, 0)))
		return ;
	if (g_print_flag == 0)
	{
		ft_putchar_fd('\n', 1);
		print_input_calling(line);
	}
	if (g_print_flag == 1)
		free(line);
	free(g_main_ptr->env->value);
	g_main_ptr->env->value = ft_itoa(1);
	g_print_flag = 0;
	return ;
}

void	sigquit(int sig)
{
	char	*line;

	sig = 0;
	if (!(line = getcwd(NULL, 0)))
		return ;
	if (g_print_flag == 1)
		ft_putstr_fd("Quit : 3", 2);
	g_print_flag = 0;
}

void	fork_signals(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	signal(SIGTERM, SIG_DFL);
}
