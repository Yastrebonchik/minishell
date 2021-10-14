/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 01:07:47 by cdelicia          #+#    #+#             */
/*   Updated: 2020/11/12 04:26:29 by cdelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		init_all_var(int *i, int *j, int *flag, t_cmd_list *tmp)
{
	int		content_len;

	*i = 0;
	*j = 0;
	*flag = 0;
	content_len = ft_strlen(tmp->content);
	return (content_len);
}

char	*put_on_new_content(t_cmd_list *tmp, char *value, int key_len)
{
	int		i;
	int		j;
	int		flag;
	char	*new_content;
	int		content_len;

	content_len = init_all_var(&i, &j, &flag, tmp);
	new_content = (char *)malloc(content_len - key_len + ft_strlen(value) + 2);
	while (tmp->content[j] != '\0')
	{
		if (tmp->content[j] == '$' && flag == 0 &&
		strong_quotes(tmp->content, j, key_len))
		{
			if (tmp->content[j + 1] != ' ')
			{
				while (*value != '\0')
					new_content[i++] = *value++;
				j += key_len;
				flag = 1;
			}
		}
		new_content[i++] = tmp->content[j++];
	}
	new_content[i] = '\0';
	return (new_content);
}

char	*allocate_key(t_cmd_list *tmp, int i)
{
	char *key;

	key = NULL;
	key = (char *)malloc(ft_strlen_key(&tmp->content[i + 1]));
	if (key == NULL)
		return (NULL);
	ft_strlcpy(key, &tmp->content[i + 1], ft_strlen_key(&tmp->content[i + 1]));
	return (key);
}

void	change_content(t_cmd_list *tmp, t_env *t_e, int i)
{
	char *ret;

	ret = put_on_new_content(tmp, t_e->value,
	ft_strlen_key(&tmp->content[i + 1]));
	free(tmp->content);
	tmp->content = ret;
}

void	fix_content(t_cmd_list *tmp, t_env *env, t_env *t_e)
{
	char		*key;
	int			i;

	i = 0;
	while (tmp->content[i] != '\0')
	{
		if (tmp->content[i] == '$' && i > 0)
			if (tmp->content[i - 1] == '\\')
				i++;
		if (tmp->content[i] == '$' && tmp->content[i + 1] != ' ')
		{
			if ((key = allocate_key(tmp, i)) == NULL)
				return ;
			while (t_e)
			{
				if (ft_strncmp(key, t_e->key, ft_strlen(t_e->key)) == 0)
					change_content(tmp, t_e, i);
				t_e = t_e->next;
			}
			free(key);
			t_e = env;
		}
		i++;
	}
	delete_all_backslash(tmp);
}
