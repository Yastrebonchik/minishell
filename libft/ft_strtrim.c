/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 23:56:57 by cdelicia          #+#    #+#             */
/*   Updated: 2020/05/14 15:27:20 by cdelicia         ###   ########.fr       */
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

char	*ft_strtrim(char const *s1, char const *set)
{
	int		s1_end;
	int		s1_start;
	char	*new_s1;
	int		i;

	i = 0;
	s1_start = 0;
	if (s1 == NULL)
		return (NULL);
	s1_end = ft_strlen(s1);
	while (s1_end > 0 && ft_isfind((char*)set, s1[s1_end - 1]))
		s1_end--;
	while (s1_start < s1_end && ft_isfind((char*)set, s1[s1_start]))
		s1_start++;
	new_s1 = (char*)malloc((s1_end - s1_start) + 1);
	if (new_s1 == NULL)
		return (NULL);
	while (i < s1_end - s1_start)
	{
		new_s1[i] = s1[s1_start + i];
		i++;
	}
	new_s1[i] = '\0';
	return (new_s1);
}
