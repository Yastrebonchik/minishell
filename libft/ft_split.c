/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 13:01:07 by cdelicia          #+#    #+#             */
/*   Updated: 2020/08/28 13:11:32 by cdelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_skip_whitespaces(char *str, char c)
{
	while (*str == c)
	{
		str++;
	}
	return (str);
}

int		ft_word_count(char *str, char c)
{
	int counter;

	counter = 0;
	while (*str != '\0')
	{
		str = ft_skip_whitespaces(str, c);
		if (*str != '\0')
		{
			counter++;
			while (*str != '\0' && *str != c)
				str++;
		}
	}
	return (counter);
}

int		ft_newword_len(char *str, char c)
{
	int len;

	len = 0;
	while (*str != '\0' && *str != c)
	{
		len++;
		str++;
	}
	return (len);
}

char	**free_array(char **arr, int i)
{
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;
	int		cut_len;
	int		word_count;

	i = 0;
	if (s == NULL)
		return (NULL);
	word_count = ft_word_count((char*)s, c);
	array = (char**)malloc(sizeof(char*) * (word_count + 1));
	if (array == NULL)
		return (NULL);
	while (word_count > 0)
	{
		s = ft_skip_whitespaces((char*)s, c);
		cut_len = ft_newword_len((char*)s, c) + 1;
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
