/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:56:30 by okandemi          #+#    #+#             */
/*   Updated: 2023/07/19 16:56:31 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	add_env(char *keyval, char **tmp, int find)
{
	int	i;

	i = 0;
	if (find == 0)
	{
		while (g_data.env[i])
		{
			tmp[i] = ft_strdup(g_data.env[i]);
			i++;
		}
		tmp[i++] = ft_strdup(keyval);
	}
	else
		add_env_success(keyval, &tmp, &i);
	free_double_pointer(&g_data.env);
	tmp[i] = NULL;
}

char	*get_env(char *key)
{
	int		i;
	char	*tmp;

	if (!g_data.env)
		return (0);
	i = 0;
	while (g_data.env[i])
	{
		tmp = ft_substr(g_data.env[i], 0, ft_strchr(g_data.env[i], '=')
				- (g_data.env[i]));
		if (ft_strcmp(key, tmp) == 0)
		{
			set_tmp(&tmp, &i);
			return (tmp);
		}
		if (tmp)
			free(tmp);
		i++;
	}
	return (0);
}

void	del_env(char *keyval, char **tmp, int find)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	if (find == 0)
		while (g_data.env[++i])
			tmp[i] = ft_strdup(g_data.env[i]);
	else
	{
		while (g_data.env[++i])
		{
			if (!ft_strncmp(keyval, g_data.env[i], ft_strchr(g_data.env[i], '=')
					- g_data.env[i]))
				;
			else
				tmp[j++] = ft_strdup(g_data.env[i]);
		}
	}
	if (find == 0)
		tmp[i] = 0;
	else
		tmp[j] = 0;
	free_double_pointer(&g_data.env);
}

void	update_env(char *keyval, int state)
{
	char	**tmp;
	int		find;
	int		i;

	find = 0;
	i = -1;
	set_keys(keyval, &find, &i);
	if (state == 1 && find == 0)
		i++;
	else if (state == -1 && find != 0)
		i--;
	tmp = malloc(sizeof(char *) * (i + 1));
	if (state == 1)
		add_env(keyval, tmp, find);
	else if (state == -1)
		del_env(keyval, tmp, find);
	g_data.env = tmp;
}
