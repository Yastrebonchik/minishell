/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 13:01:07 by cdelicia          #+#    #+#             */
/*   Updated: 2020/11/11 20:29:21 by cdelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_skip_setspaces(char *str)
{
	while (*str != '\0' && *str == ';')
		str++;
	return (str);
}

static int	ft_word_count(char *str)
{
	int		counter;
	char	*start_str;

	counter = 0;
	start_str = str;
	while (*str != '\0')
	{
		str = ft_skip_setspaces(str);
		if (*str != '\0')
		{
			if (check_scope_for_echo(start_str, str) == 0)
				counter++;
			while (*str != '\0' && *str != ';')
				str++;
		}
	}
	return (counter);
}

static int	ft_newword_len(char *str)
{
	int		len;
	char	*start_str;

	len = 0;
	start_str = str;
	while (*str != '\0' && *str != ';')
	{
		len++;
		str++;
		if (*str != '\0')
		{
			if (*str == ';')
			{
				if (check_scope_for_echo(start_str, str) == 1)
				{
					len++;
					str++;
				}
			}
		}
	}
	return (len);
}

static char	**free_array(char **arr, int i)
{
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
	return (NULL);
}

char		**ft_split_echo(char *s)
{
	char	**array;
	int		i;
	int		cut_len;
	int		word_count;

	i = 0;
	if (s == NULL)
		return (NULL);
	word_count = ft_word_count((char*)s);
	array = (char**)malloc(sizeof(char*) * (word_count + 1));
	if (array == NULL)
		return (NULL);
	while (word_count > 0)
	{
		cut_len = ft_newword_len((char*)s) + 1;
		array[i] = (char*)malloc(cut_len);
		if (array[i] == NULL)
			return (free_array(array, i - 1));
		ft_strlcpy(array[i++], s, cut_len);
		s = s + cut_len;
		word_count--;
	}
	array[i] = NULL;
	return (array);
}
