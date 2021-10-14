/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 00:42:35 by cdelicia          #+#    #+#             */
/*   Updated: 2020/11/11 00:43:20 by cdelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	too_many_arguments(t_main *data)
{
	ft_putstr_fd("too many arguments\n", 2);
	change_return_env_var(1, data);
}

void	not_valid_identifier(t_main *data)
{
	ft_putstr_fd("Not a valid identifier\n", 2);
	change_return_env_var(1, data);
}
