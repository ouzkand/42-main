/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:53:39 by okandemi          #+#    #+#             */
/*   Updated: 2023/07/28 18:36:15 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	print_env(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (ft_strchr(str[i], '=') != NULL)
			printf("%s\n", str[i]);
	}
}

void	n_ctl(char **arg, int i)
{
	if (ft_strcmp(arg[0], "-n") == 1)
	{
		while (arg[i])
		{
			if (ft_strcmp(arg[i], "-n") == 1 || ft_strcmp(arg[i], " ") == 1)
				i++;
		}
	}
}

void	ft_builtins(char **cmnd, char **cmnd_upper)
{
	int		nbr;

	nbr = 0;
	if (ft_strcmp(cmnd[0], "echo") == 0)
		ft_echo(&cmnd[1]);
	else if (ft_strcmp(cmnd[0], "clear") == 0)
		printf("\e[1;1H\e[2J");
	else if (ft_strcmp(cmnd[0], "pwd") == 0)
		printf("%s\n", getcwd(g_data.path, 4096));
	else if (ft_strcmp(cmnd[0], "cd") == 0)
		nbr = ft_cd(cmnd[1], g_data.path);
	else if (ft_strcmp(cmnd[0], "env") == 0)
		print_env(g_data.env);
	else if (ft_strcmp(cmnd[0], "export") == 0)
		nbr = do_export(cmnd_upper);
	else if (ft_strcmp(cmnd[0], "unset") == 0)
		nbr = ft_unset(cmnd_upper);
	else if (ft_strcmp(cmnd[0], "exit") == 0)
	{
		exit_func(cmnd);
		return ;
	}
	g_data.exit_status = nbr;
}
