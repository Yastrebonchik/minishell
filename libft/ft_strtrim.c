/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 23:56:57 by cdelicia          #+#    #+#             */
/*   Updated: 2020/11/12 06:17:09 by cdelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isfind(char *set, char symbol)
{
	while (*set != '\0')
	{
		if (*set == symbol)
			return (1);
		set++;
	}
	return (0);
}

int		echo_or_not(char const *line)
{
	while (*line != '\0')
	{
		if (*line == 'e')
			if (*(line + 1) == 'c')
				if (*(line + 2) == 'h')
					if (*(line + 3) == 'o')
						return (5);
		line++;
	}
	return (0);
}

char	*ft_kostyl(int *j, char const *s1, int *s1_start)
{
	char *new_s1;

	new_s1 = NULL;
	if ((*s1_start = echo_or_not(s1)) == 5)
	{
		new_s1 = (char *)malloc(ft_strlen(s1) + 1);
		while (*j < 5)
		{
			new_s1[*j] = s1[*j];
			*j += 1;
		}
	}
	return (new_s1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		s1_end;
	int		s1_start;
	char	*new_s1;
	int		j;
	int		i;

	i = 0;
	j = 0;
	new_s1 = ft_kostyl(&j, s1, &s1_start);
	s1_end = ft_strlen(s1);
	while (s1_end > 0 && ft_isfind((char*)set, s1[s1_end - 1]))
		s1_end--;
	while (s1_start < s1_end && ft_isfind((char*)set, s1[s1_start]))
		s1_start++;
	if (new_s1 == NULL)
		new_s1 = (char*)malloc((s1_end - s1_start) + 1);
	while (i < s1_end - s1_start)
	{
		new_s1[j] = s1[s1_start + i];
		i++;
		j++;
	}
	new_s1[j] = '\0';
	return (new_s1);
}
