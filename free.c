/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 01:07:47 by cdelicia          #+#    #+#             */
/*   Updated: 2020/10/26 02:57:45 by cdelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_all_array_elements(char **arr, int i)
{
	if (arr)
	{
		while (i >= 0)
		{
			free(arr[i]);
			i--;
		}
		free(arr);
	}
}
