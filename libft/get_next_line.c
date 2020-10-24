/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 14:39:57 by cdelicia          #+#    #+#             */
/*   Updated: 2020/08/28 15:34:44 by cdelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_next_line(int fd, char **line)
{
	char		buf[32];
	static char	*static_buf;
	ssize_t		i;
	char		*line_break;

	if (line == NULL || fd < 0)
		return (-1);
	while ((i = read(fd, buf, 31)) > 0)
	{
		buf[i] = '\0';
		static_buf = gnl_strjoin(static_buf, buf);
		if ((line_break = gnl_strchr(static_buf, '\n')) != NULL)
			return (ft_cut_line(&static_buf, line, line_break));
	}
	if (i < 0)
		return (-1);
	return (ft_whole_line(&static_buf, line));
}

int		ft_cut_line(char **s, char **line, char *n)
{
	char	*tmp;

	*n = '\0';
	*line = gnl_strdup(*s);
	if (*(n + 1) == '\0')
	{
		free(*s);
		*s = NULL;
	}
	else
	{
		tmp = gnl_strdup(n + 1);
		free(*s);
		*s = tmp;
	}
	return (1);
}

int		ft_whole_line(char **s, char **line)
{
	char	*line_break;

	if (*s != NULL && (line_break = gnl_strchr(*s, '\n')) != NULL)
		return (ft_cut_line(s, line, line_break));
	if (*s != NULL)
	{
		*line = *s;
		*s = NULL;
		return (0);
	}
	*line = gnl_strdup("");
	return (0);
}
