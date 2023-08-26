/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:54:07 by okandemi          #+#    #+#             */
/*   Updated: 2023/07/19 16:54:08 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	size_env(char **env)
{
	int	res;

	res = 0;
	while (env[res])
		res++;
	return (res);
}

int	size_expand_len(char *cmd)
{
	int		res;
	char	*env_name;

	if (ft_strchr(cmd, '='))
		env_name = ft_substr(cmd, 0, ft_strchr(cmd, '=') - cmd);
	else
		env_name = ft_strdup(cmd);
	res = repeat_index(env_name, cmd);
	free(env_name);
	return (res);
}

int	is_env(char *str)
{
	int		i;
	char	*env;

	i = 0;
	while (g_data.env[i])
	{
		env = env_name(i);
		if (!ft_strcmp(env, str))
		{
			free(env);
			return (i);
		}
		free(env);
		i++;
	}
	return (-1);
}

void	exit_func(char **cmnd)
{
	int	nbr;

	nbr = 0;
	printf("exit\n");
	if (cmnd[1])
	{
		nbr = getting_number_in_exit(cmnd[1]);
		if (nbr == 0)
			nbr = ft_atoi(cmnd[1]);
	}
	if (cmnd[1] && cmnd[2])
	{
		g_data.exit_status = 1;
		printf("minishell: exit: too many arguments\n");
		return ;
	}
	exit(nbr);
}
