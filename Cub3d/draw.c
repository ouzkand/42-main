/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:16:00 by okandemi          #+#    #+#             */
/*   Updated: 2023/10/05 15:25:22 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pxl_to_img(t_cub3d *cub3d, int x, int y, int color)
{
	char	*dst;

	dst = cub3d->image.data + (y * cub3d->image.sizeline + x \
		* (cub3d->image.bpp / 8));
	*(unsigned int *)dst = color;
}

void	put_mini_map_red_dot(t_cub3d *cub3d, int color)
{
	int	i;
	int	j;

	i = -2;
	while (++i < 2)
	{
		j = -2;
		while (++j < 2)
		{
			put_pxl_to_img(cub3d, cub3d->player->x * cub3d->length_x + i, \
				cub3d->player->y * cub3d->length_y + j, color);
			put_pxl_to_img(cub3d, (cub3d->player->x + cub3d->player->dir_x \
				+ cub3d->player->plane_x) * cub3d->length_x + i, \
				(cub3d->player->y - cub3d->player->dir_y - \
				cub3d->player->plane_y) * cub3d->length_y + j, color);
			put_pxl_to_img(cub3d, (cub3d->player->x + cub3d->player->dir_x \
				- cub3d->player->plane_x) * cub3d->length_x + i, \
				(cub3d->player->y - cub3d->player->dir_y + \
				cub3d->player->plane_y) * cub3d->length_y + j, color);
		}
	}
}

void	draw_maze(t_cub3d *cub3d)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = -1;
	while (++i < cub3d->line_count)
	{
		j = -1;
		while (++j < cub3d->max_line)
		{
			if (cub3d->int_map[i][j] == 1)
			{
				k = -1;
				while (++k < cub3d->length_x)
				{
					l = -1;
					while (++l < cub3d->length_y)
						put_pxl_to_img(cub3d, (j * cub3d->length_x) + k, \
						(i * cub3d->length_y) + l, 0xFFFFFF);
				}
			}
		}
	}
}

void	draw_pause(t_cub3d *cub3d, int color)
{
	int	i;
	int	j;

	if (!cub3d->lock)
		return ;
	i = 3 * WIDTH / 8 - 1;
	while (++i < (15 * WIDTH) / 32)
	{
		j = HEIGHT / 3 - 1;
		while (++j < (2 * HEIGHT) / 3)
			put_pxl_to_img(cub3d, i, j, color);
	}
	i = (17 * WIDTH) / 32 - 1;
	while (++i < (5 * WIDTH) / 8)
	{
		j = HEIGHT / 3 - 1;
		while (++j < (2 * HEIGHT) / 3)
			put_pxl_to_img(cub3d, i, j, color);
	}
}
