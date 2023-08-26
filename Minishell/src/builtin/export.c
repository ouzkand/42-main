/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:53:54 by okandemi          #+#    #+#             */
/*   Updated: 2023/07/19 16:53:55 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	repeat_index(char *env_name, char *cmd)
{
	char	*env;
	int		i;

	i = 0;
	while (g_data.env[i])
	{
		if (ft_strchr(g_data.env[i], '='))
			env = ft_substr(g_data.env[i],
					0, ft_strchr(g_data.env[i], '=') - g_data.env[i]);
		else
			env = ft_strdup(g_data.env[i]);
		if (!ft_strcmp(env, env_name))
		{
			free(env);
			if ((ft_strchr(g_data.env[i], '=') && ft_strchr(cmd, '='))
				|| !ft_strchr(g_data.env[i], '='))
				return (i);
			else
				return (-2);
		}
		free(env);
		i++;
	}
	return (-1);
}

void	add_env_new2(char *cmd, char **tmp)
{
	int	i;

	i = 0;
	while (g_data.env[i])
	{
		tmp[i] = ft_strdup(g_data.env[i]);
		i++;
	}
	tmp[i++] = ft_strdup(cmd);
	tmp[i] = NULL;
	free_double_pointer(&g_data.env);
	g_data.env = tmp;
}

void	add_env_new(char *cmd)
{
	char	**tmp;
	int		len;
	int		repeat_index;

	len = size_env(g_data.env);
	repeat_index = size_expand_len(cmd);
	if (repeat_index == -1)
		tmp = malloc(sizeof(char *) * (len + 2));
	else if (repeat_index == -2)
		return ;
	else
	{
		free (g_data.env[repeat_index]);
		g_data.env[repeat_index] = ft_strdup(cmd);
		return ;
	}
	add_env_new2(cmd, tmp);
}

void	print_export(char *str)
{
	int		i;
	int		k;
	char	*is;

	i = 0;
	k = 0;
	while (g_data.env[i])
	{
		is = ft_strchr(g_data.env[i], '=');
		k = 0;
		printf("%s", str);
		while (g_data.env[i][k])
		{
			if (k != 0 && g_data.env[i][k - 1] == '=' && str && is)
				printf("\"");
			printf("%c", g_data.env[i][k]);
			if (!g_data.env[i][k + 1] && str && is)
				printf("\"");
			k++;
		}
		if (g_data.env[i][k - 1] == '=')
			printf("\"");
		printf("\n");
		i++;
	}
}

int	do_export(char **cmnds)
{
	int	i;

	if (is_invalid_arg(cmnds) != -1)
	{
		printf("minishell: export: `%s': not a valid identifier\n",
			cmnds[is_invalid_arg(cmnds)]);
		return (1);
	}
	if (!cmnds[1])
		print_export("declare -x ");
	else
	{
		i = 1;
		while (cmnds[i])
			add_env_new(cmnds[i++]);
	}
	return (0);
}
