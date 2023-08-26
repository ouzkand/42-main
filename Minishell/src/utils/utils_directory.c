/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_directory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:56:15 by okandemi          #+#    #+#             */
/*   Updated: 2023/07/19 16:56:16 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	find_dir2(struct dirent *dir, DIR *d, char *cmd, int i)
{
	if (ft_strncmp(dir->d_name, ".", ft_strlen(dir->d_name)) != 0
		&& ft_strncmp(dir->d_name, "..",
			ft_strlen(dir->d_name)) != 0)
	{
		if (!ft_strncmp(dir->d_name, cmd, ft_strlen(cmd))
			&& ft_strlen(cmd) == ft_strlen(dir->d_name))
		{
			closedir(d);
			return (i);
		}
	}
	return (-1);
}

int	find_dir(char **path, char *cmd)
{
	struct dirent	*dir;
	DIR				*d;
	int				i;
	int				tmp;

	i = 0;
	d = opendir(path[i]);
	while (d)
	{
		dir = readdir(d);
		while (dir != NULL)
		{
			tmp = find_dir2(dir, d, cmd, i);
			if (tmp != -1)
				return (tmp);
			dir = readdir(d);
		}
		closedir(d);
		d = opendir(path[++i]);
	}
	free(d);
	free(dir);
	return (-1);
}

char	*add_path(int index, char *cmnd, char **paths)
{
	char	*res;
	char	*tmp;

	tmp = ft_strjoin(paths[index], "/");
	res = ft_strjoin(tmp, cmnd);
	free(tmp);
	return (res);
}
