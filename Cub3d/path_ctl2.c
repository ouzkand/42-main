/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_ctl2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:25:41 by okandemi          #+#    #+#             */
/*   Updated: 2023/10/07 16:03:11 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	text_len(t_cub3d *cub3d)
{
	if (ft_strlen(cub3d->map_info->north) < 6 || \
		ft_strlen(cub3d->map_info->east) < 6 || \
		ft_strlen(cub3d->map_info->west) < 6 || \
		ft_strlen(cub3d->map_info->south) < 6 || \
		ft_strlen(cub3d->map_info->c) < 6 || ft_strlen(cub3d->map_info->f) < 6)
	{
		err_data_ctl("ERROR! Text paths does not found! \n", cub3d);
		exit (1);
	}
}

int	check_player(t_cub3d *vals, int i, int j)
{
	static int	player_count;

	if (vals->map[i][j] == 'N' || vals->map[i][j] == 'S' ||
		vals->map[i][j] == 'W' || vals->map[i][j] == 'E')
		player_count++;
	return ((int) player_count);
}

int	is_user_zero(int c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

void	find_longest_line(t_cub3d *cub3d)
{
	int		i;

	i = -1;
	cub3d->max_line = ft_strlen(cub3d->map[0]);
	while (cub3d->map[++i])
	{
		if (ft_strlen(cub3d->map[i]) > cub3d->max_line)
			cub3d->max_line = ft_strlen(cub3d->map[i]);
	}
}

void	find_line_count(t_cub3d *cub3d)
{
	char	**tmp;

	tmp = cub3d->map;
	while (*tmp)
	{
		cub3d->line_count++;
		tmp++;
	}
}
