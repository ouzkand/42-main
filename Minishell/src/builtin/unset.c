/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:54:03 by okandemi          #+#    #+#             */
/*   Updated: 2023/07/19 16:54:04 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	is_invalid_arg(char **str)
{
	int	i;
	int	k;

	i = 1;
	while (str[i])
	{
		if (str[i][0] == '=')
			return (i);
		k = 0;
		while (str[i][k])
		{
			if (str[i][k] == '=')
				break ;
			if (ft_isdigit(str[i][0]))
				return (i);
			if ((!ft_isalpha(str[i][k]) && \
				!ft_isdigit(str[i][k]) && str[i][k] != '_')
					|| str[i][k] == ' ')
				return (i);
			k++;
		}
		i++;
	}
	return (-1);
}

int	arg_counter(char **str)
{
	if (!str)
		return (0);
	return (1 + arg_counter(str + 1));
}

char	*env_name(int i)
{
	char	*env;

	if (ft_strchr(g_data.env[i], '='))
		env = ft_substr(g_data.env[i],
				0, ft_strchr(g_data.env[i], '=') - g_data.env[i]);
	else
		env = ft_strdup(g_data.env[i]);
	return (env);
}

void	ft_unset2(char *str)
{
	char	**tmp;
	char	*env;
	int		i;
	int		k;

	tmp = malloc(sizeof(char *) * (size_env(g_data.env)));
	i = 0;
	k = 0;
	while (g_data.env[i])
	{
		env = env_name(i);
		if (!ft_strcmp(env, str))
		{
			i++;
			free(env);
			continue ;
		}
		free(env);
		tmp[k++] = ft_strdup(g_data.env[i++]);
	}
	tmp[k] = NULL;
	free_double_pointer(&g_data.env);
	g_data.env = tmp;
}

int	ft_unset(char **str)
{
	int	i;

	i = 1;
	if (is_invalid_arg(str) != -1)
	{
		printf("minishell: unset: `%s': not a valid identifier\n",
			str[is_invalid_arg(str)]);
		return (1);
	}
	while (str[i])
	{
		if (is_env(str[i]) == -1)
		{
			i++;
			break ;
		}
		ft_unset2(str[i++]);
	}
	return (0);
}
