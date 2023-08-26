/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyvals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:56:38 by okandemi          #+#    #+#             */
/*   Updated: 2023/07/19 16:56:39 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	set_tmp(char **tmp, int *i)
{
	char	**str;

	if (*tmp)
		free(*tmp);
	str = ft_split(g_data.env[*i], '=');
	*tmp = ft_strdup(str[1]);
	free(str[0]);
	free(str[1]);
	free(str);
}

void	set_keys(char *keyval, int *find, int *i)
{
	char	*key1;
	char	*key2;

	while (g_data.env[++(*i)])
	{
		key1 = ft_substr(keyval, 0, ft_strchr(keyval, '=') - keyval);
		key2 = ft_substr(g_data.env[*i], 0, ft_strchr(g_data.env[*i], '=')
				- g_data.env[*i]);
		if (!ft_strcmp(key1, key2))
			(*find)++;
		free(key1);
		free(key2);
	}
}
