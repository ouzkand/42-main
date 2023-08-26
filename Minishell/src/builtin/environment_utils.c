/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:56:24 by okandemi          #+#    #+#             */
/*   Updated: 2023/07/19 16:56:27 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	set_pwds(char *old_dir, int find)
{
	int		i;
	char	*tmp;

	i = 0;
	while (g_data.env[i])
	{
		if (ft_strncmp(g_data.env[i], "OLDPWD", 6) == 0 && find != 0)
		{
			free(g_data.env[i]);
			g_data.env[i] = ft_strjoin("OLDPWD=", old_dir);
		}
		else if (ft_strncmp(g_data.env[i], "PWD", 3) == 0)
		{
			tmp = getcwd(NULL, 4096);
			free(g_data.env[i]);
			g_data.env[i] = ft_strjoin("PWD=", tmp);
			free(tmp);
		}
		i++;
	}
}

void	update_env_pwds(char *old_dir)
{
	int		i;
	int		find;
	char	*tmp;

	find = 0;
	i = -1;
	while (g_data.env[++i])
		if (ft_strncmp(g_data.env[i], "OLDPWD", 6) == 0)
			find++;
	if (find == 0)
	{
		tmp = ft_strjoin("OLDPWD=", old_dir);
		update_env(tmp, 1);
		free(tmp);
	}
	set_pwds(old_dir, find);
}

void	add_env_success(char *keyval, char ***tmp, int *i)
{
	char	*key1;
	char	*key2;

	while (g_data.env[++(*i)])
	{
		if (ft_strchr(keyval, '=') != NULL)
		{
			key1 = ft_substr(keyval, 0, ft_strchr(keyval, '=') - keyval);
			key2 = ft_substr(g_data.env[*i], 0,
					ft_strchr(g_data.env[*i], '=') - g_data.env[*i]);
			if (!ft_strcmp(key1, key2))
				(*tmp)[*i] = ft_strdup(keyval);
			else
				(*tmp)[*i] = ft_strdup(g_data.env[*i]);
			free(key1);
			free(key2);
		}
		else
			(*tmp)[*i] = ft_strdup(g_data.env[*i]);
	}
}
