/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:54:44 by okandemi          #+#    #+#             */
/*   Updated: 2023/07/19 16:54:46 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	is_executor(char **expand_cmd)
{
	if (expand_cmd[0][0] == '/')
		return (2);
	else if (expand_cmd[0][0] == '.' && expand_cmd[0][1] == '/')
		return (1);
	else
		return (0);
}

void	file_add2(char **file, char **paths, t_cmnd *t_cmd, int index)
{
	if (built_in_ctl(t_cmd->expand_cmnd_lower[0]))
	{
		*file = NULL;
		return ;
	}
	else if (index == -1 && is_executor(t_cmd->expand_cmnd))
	{
		printf("minishell: %s: No such file or directory\n",
			t_cmd->expand_cmnd[0]);
		exit(127);
	}
	if (index != -1)
		*file = add_path(index, t_cmd->expand_cmnd_lower[0], paths);
	else
		*file = NULL;
}

void	file_add(char **file, char **paths, t_cmnd *t_cmd)
{
	int	index;

	index = find_dir(paths, t_cmd->expand_cmnd_lower[0]);
	if (is_executor(t_cmd->expand_cmnd) == 1)
		index = find_dir(paths, t_cmd->expand_cmnd_lower[0] + 2);
	else if (is_executor(t_cmd->expand_cmnd) == 2 && \
			!access(t_cmd->expand_cmnd_lower[0], X_OK))
	{
		*file = ft_strdup(t_cmd->expand_cmnd_lower[0]);
		return ;
	}
	if (is_directory(t_cmd->expand_cmnd_lower[0] + 2)
		&& is_executor(t_cmd->expand_cmnd) == 1)
	{
		printf("minishell: %s: is a directory\n", t_cmd->expand_cmnd[0]);
		exit (126);
	}
	file_add2(file, paths, t_cmd, index);
}

int	is_directory(char *expand_cmnd)
{
	DIR	*d;

	d = opendir(expand_cmnd);
	if (d)
	{
		closedir(d);
		return (1);
	}
	return (0);
}

void	upper_to_lower(t_cmnd *t_cmd)
{
	int		i;
	int		k;

	while (t_cmd)
	{
		i = 0;
		k = 0;
		while (t_cmd->expand_cmnd_lower[i] && t_cmd->expand_cmnd_lower[i][k])
		{
			if (t_cmd->expand_cmnd_lower[i][k] >= 'A'
				&& t_cmd->expand_cmnd_lower[i][k] <= 'Z')
				t_cmd->expand_cmnd_lower[i][k] = t_cmd->expand_cmnd_lower[i][k]
					+ 32;
			if (t_cmd->expand_cmnd[i]
				&& t_cmd->expand_cmnd_lower[i][k + 1] == '\0')
			{
				i++;
				k = 0;
				continue ;
			}
			k++;
		}
		t_cmd = t_cmd->next;
	}
}
