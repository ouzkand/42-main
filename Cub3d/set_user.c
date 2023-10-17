/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_user.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:30:37 by okandemi          #+#    #+#             */
/*   Updated: 2023/10/07 14:48:04 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_dir(t_cub3d *cub3d, int i, int j)
{
	if (cub3d->map[i][j] == 'N')
	{
		cub3d->player->plane_x = 0.66;
		cub3d->player->dir_y = 1.0;
	}
	else if (cub3d->map[i][j] == 'S')
	{
		cub3d->player->plane_x = -0.66;
		cub3d->player->dir_y = -1.0;
	}
	else if (cub3d->map[i][j] == 'E')
	{
		cub3d->player->dir_x = 1.0;
		cub3d->player->plane_y = -0.66;
	}
	else if (cub3d->map[i][j] == 'W')
	{
		cub3d->player->dir_x = -1.0;
		cub3d->player->plane_y = 0.66;
	}
}

void	set_user(t_cub3d *cub3d, int i, int j)
{
	cub3d->player->x = j + 0.5;
	cub3d->player->y = i + 0.5;
	set_player_dir(cub3d, i, j);
	cub3d->int_map[i][j] = 0;
}

void	free_map_info(t_cub3d *cub3d)
{
	if (cub3d->map_info->c)
		free (cub3d->map_info->c);
	if (cub3d->map_info->north)
		free (cub3d->map_info->north);
	if (cub3d->map_info->east)
		free (cub3d->map_info->east);
	if (cub3d->map_info->west)
		free (cub3d->map_info->west);
	if (cub3d->map_info->south)
		free (cub3d->map_info->south);
	if (cub3d->map_info->f)
		free (cub3d->map_info->f);
	free(cub3d->map_info);
}
