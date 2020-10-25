/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 00:07:59 by cdelicia          #+#    #+#             */
/*   Updated: 2020/10/25 03:48:13 by cdelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	exec_command()
// {

// }

void		threads_change(t_main *main)
{
	dup2(main->input, 0);    /*for your future work with threads*/
	dup2(main->output, 1);
}

void	print_input_calling(char *s)
{
	ft_putstr_fd("\033[32m", 1);    /*green clr*/
	ft_putstr_fd("minishell:", 1);
	ft_putstr_fd(s, 1);             /*current directory*/
	ft_putstr_fd(" ", 1);
	ft_putstr_fd(">$", 1);          /*input calling*/
	ft_putstr_fd("\033[0m", 1);     /*return standart clr*/
	ft_putstr_fd(" ", 1);
	free(s);
	//my_signals();                 /*need to read about signals*/
		//signal(SIGINT, my_func);
		//signal(SIGQUIT, my_func);
		//signal(15, SIG_IGN);
}

void	initialization_all(t_main *main)
{
	g_main_ptr = main;
	ft_bzero(main, sizeof(*main));
	main->env = (t_env *)malloc(sizeof(t_env));   /*first allocate*/
	main->list = (t_cmd_list *)malloc(sizeof(t_cmd_list));
}

void	clear_parced_env_list(t_main *main)
{
	if (main->env)
		free(main->env);   /*not free all list, use ft_lstclear()*/
	//ft_lstclear(&main->env, free);
}

void	clear_parced_cmd_list(t_main *main)
{
	if (main->list)
		free(main->list);   /*not free all list, use ft_lstclear()*/
	//ft_lstclear(&main->list, free);
}

int		main(int argc, char **argv, char **envp)
{
	t_main	main;

	if (argc != 1)
	{
		ft_putstr_fd("Wrong number of arguments\n", 2);
		return (1);
	}
	argv[0][0] = 'e';                /*for what?*/
	initialization_all(&main);       /*init all struct*/
	env_transform(envp, &main.env);  /*parsing env*/
	while (1)
	{
		ft_parcing(&main);
		
		//look down -> code in read_line() and ft_parcing()

		clear_parced_cmd_list(&main);
	}
	clear_parced_env_list(&main);
	return (0);
}

int		read_line(char *line, t_main *data)
{
	int		i;
	int		ret;
	char	**cur_commands;

	i = 0;
	ret = 0;
	data->separator = ';';
	if (!(cur_commands = ft_split(line, ' ')))
		return (1);
	while (cur_commands[i] != NULL)
	{
		ret = ft_check_command(cur_commands[0]);
		if (ret == 1)
			echo(cur_commands);
		if (ret == 2)
			;//ft_cd();
		if (ret == 3)
			pwd();
		if (ret == 4)
		{
			printf("exit\n");
			free_all_array_elements(cur_commands, array_len(cur_commands));
			exit(0);
		}
		if (ret == 5)
			env_print(data->env);
		i++;
	}
	free_all_array_elements(cur_commands, array_len(cur_commands));
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
		read_line(line, data);   /*magic will be here*/
	free(line);
	return (0);
}

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

char			*delete_whitespaces(char *line)
{
	int i;

	if (line)
	{
		while (*line == ' ')    /*delete ' ' before line*/
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

void	free_all_array_elements(char **arr, int i)
{
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
}

int		array_len(char **cur_commands)
{
	int i;

	i = 0;
	if (cur_commands)
		while (cur_commands[i] != NULL)
			i++;
	return (i);
}
