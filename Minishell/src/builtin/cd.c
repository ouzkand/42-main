/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:53:44 by okandemi          #+#    #+#             */
/*   Updated: 2023/07/28 17:37:50 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

char	*tilde_path(char *dest)
{
	char	*res;
	char	*tmp;

	if (dest[0] != '~')
		return (dest);
	tmp = get_env("HOME");
	res = add_path(0, dest + 1, &tmp);
	free(tmp);
	return (res);
}

void	ft_cd2(void)
{
	char	*key;

	key = get_env("HOME");
	if (!key)
		printf("minishell : HOME not set\n");
	if (chdir(key) == -1)
		printf("error chdir\n");
	free(key);
}

int	ft_cd(char *dest, char *old_dir)
{
	char	*key;

	getcwd(g_data.path, 4096);
	if (!dest || (dest[0] == '~' && !dest[1]))
	{
		ft_cd2();
	}
	else
	{
		key = tilde_path(dest);
		if (access(key, X_OK) == 0)
			chdir(key);
		else if (ENOENT == errno)
		{
			printf("minishell: cd: %s: No such file or directory\n", dest);
			return (1);
		}
		if (dest[0] == '~')
			free(key);
	}
	update_env_pwds(old_dir);
	getcwd(g_data.path, 4096);
	return (0);
}
