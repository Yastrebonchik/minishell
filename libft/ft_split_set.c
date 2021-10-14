/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 20:36:23 by cdelicia          #+#    #+#             */
/*   Updated: 2020/11/11 20:32:26 by cdelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_skip_setspaces(char *str, char *set)
{
	while (ft_strchr(set, *str))
		str++;
	return (str);
}

static int	ft_word_count(char *str, char *set)
{
	int		counter;
	char	*start_str;

	counter = 0;
	start_str = str;
	while (*str != '\0')
	{
		str = ft_skip_setspaces(str, set);
		if (*str != '\0')
		{
			if (check_scope_for_echo(start_str, str) == 0)
				counter++;
			else
				start_str = str;
			while (*str != '\0' && ft_strchr(set, *str) == NULL)
				str++;
		}
	}
	return (counter);
}

static int	ft_newword_len(char *str, char *set)
{
	int		len;
	char	*start;

	len = 0;
	start = str;
	while (*str != '\0' && ft_strchr(set, *str) == NULL)
	{
		len++;
		str++;
		if (*str != '\0')
			if (ft_strchr(set, *str))
				if (check_scope_for_echo(start, str) == 1)
				{
					str++;
					len++;
				}
	}
	if (*str == '\0')
		return (len);
	if (*str == '>')
		if (*(str + 1) == '>')
			return (len + 2);
	if (*str == '<' || *str == '|' || *str == '>')
		return (len + 1);
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

char		**ft_split_set(char *s, char *set)
{
	char	**array;
	int		i;
	int		cut_len;
	int		word_count;

	i = 0;
	if (s == NULL)
		return (NULL);
	word_count = ft_word_count((char*)s, set);
	array = (char**)malloc(sizeof(char*) * (word_count + 1));
	if (array == NULL)
		return (NULL);
	while (word_count > 0)
	{
		cut_len = ft_newword_len((char*)s, set) + 1;
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
