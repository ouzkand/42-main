/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:00:43 by ydegerli          #+#    #+#             */
/*   Updated: 2023/10/05 15:27:36 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	get_pixel_in_tex(t_image tex, int x, int y)
{
	char	*dst;

	dst = tex.data + (y * tex.sizeline + x * (tex.bpp / 8));
	return (*((unsigned int *) dst));
}

void	split_screen_two(t_cub3d *cub3d, t_math *math)
{
	math->raydir_x = \
	cub3d->player->dir_x + cub3d->player->plane_x * math->camera_x;
	math->raydir_y = \
	-cub3d->player->dir_y + -cub3d->player->plane_y * math->camera_x;
	math->map_x = (int)cub3d->player->x;
	math->map_y = (int)cub3d->player->y;
	if (math->raydir_x == 0)
		math->deltadist_x = 1e30;
	else
		math->deltadist_x = fabs(1 / math->raydir_x);
	if (math->raydir_y == 0)
		math->deltadist_y = 1e30;
	else
		math->deltadist_y = fabs(1 / math->raydir_y);
	math->hit = 0;
}

void	calculating_rays(t_cub3d *cub3d, t_math *math)
{
	if (math->raydir_x < 0)
	{
		math->step_x = -1;
		math->sidedist_x = (cub3d->player->x - math->map_x) * math->deltadist_x;
	}
	else
	{
		math->step_x = 1;
		math->sidedist_x = \
		(math->map_x + 1.0 - cub3d->player->x) * math->deltadist_x;
	}
	if (math->raydir_y < 0)
	{
		math->step_y = -1;
		math->sidedist_y = \
		(cub3d->player->y - math->map_y) * math->deltadist_y;
	}
	else
	{
		math->step_y = 1;
		math->sidedist_y = \
		(math->map_y + 1.0 - cub3d->player->y) * math->deltadist_y;
	}
}
