/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:52:53 by ydegerli          #+#    #+#             */
/*   Updated: 2023/10/07 18:28:40 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	does_ray_hitting_wall(t_cub3d *cub3d, t_math *math)
{
	while (math->hit == 0)
	{
		if (math->sidedist_x < math->sidedist_y)
		{
			math->sidedist_x += math->deltadist_x;
			math->map_x += math->step_x;
			math->side = 0;
		}
		else
		{
			math->sidedist_y += math->deltadist_y;
			math->map_y += math->step_y;
			math->side = 1;
		}
		if (cub3d->int_map[math->map_y][math->map_x] > 0)
			math->hit = 1;
	}
}

void	calculating_drawing_screen_and_fisheye_ctl(t_cub3d *cub3d, t_math *math)
{
	if (math->side == 0)
		math->perpwalldist = (math->sidedist_x - math->deltadist_x);
	else
		math->perpwalldist = (math->sidedist_y - math->deltadist_y);
	math->lineheight = (int)(HEIGHT / math->perpwalldist);
	math->pitch = 100;
	math->drawstart = -math->lineheight / 2 + HEIGHT / 2 + math->pitch;
	if (math->drawstart < 0)
		math->drawstart = 0;
	math->drawend = math->lineheight / 2 + HEIGHT / 2 + math->pitch;
	if (math->drawend >= HEIGHT)
		math->drawend = HEIGHT - 1;
	math->texnum = cub3d->int_map[math->map_y][math->map_x] - 1;
	if (math->side == 0)
		math->wall_x = cub3d->player->y + math->perpwalldist * math->raydir_y;
	else
		math->wall_x = cub3d->player->x + math->perpwalldist * math->raydir_x;
	math->wall_x -= floor(math->wall_x);
	math->tex_x = (double)(math->wall_x * TEXTWIDHT);
	if (math->side == 0 && math->raydir_x > 0)
		math->tex_x = TEXTWIDHT - math->tex_x - 1;
	if (math->side == 1 && math->raydir_y < 0)
		math->tex_x = TEXTWIDHT - math->tex_x - 1;
}

void	drawing_screen(t_cub3d *cub3d, t_math *math)
{
	math->tex_x = TEXTWIDHT - math->tex_x - 1;
	math->step = 1.0 * TEXTHEIGHT / math->lineheight;
	math->texpos = \
	(math->drawstart - math->pitch - HEIGHT / 2 + math->lineheight / 2) \
	* math->step;
}

void	painting(t_cub3d *cub3d, int ct, int ctt, unsigned int color)
{
	t_math	*math;
	int		tex;

	math = &(cub3d->math);
	while (ctt++ < math->drawstart)
		put_pxl_to_img(cub3d, ct, ctt, create_trgb(0, cub3d->sky.r, \
			cub3d->sky.g, cub3d->sky.b));
	while (ctt++ < math->drawend)
	{
		tex = (int) math->texpos & (TEXTHEIGHT - 1);
		math->texpos += math->step;
		if (math->side == 0 && math->raydir_x > 0)
			color = get_pixel_in_tex(cub3d->west, math->tex_x, tex);
		if (math->side == 0 && math->raydir_x < 0)
			color = get_pixel_in_tex(cub3d->east, math->tex_x, tex);
		if (math->side == 1 && math->raydir_y > 0)
			color = get_pixel_in_tex(cub3d->north, math->tex_x, tex);
		if (math->side == 1 && math->raydir_y < 0)
			color = get_pixel_in_tex(cub3d->south, math->tex_x, tex);
		put_pxl_to_img(cub3d, ct, ctt, color);
	}
	while (ctt++ < HEIGHT - 1)
		put_pxl_to_img(cub3d, ct, ctt, create_trgb(0, cub3d->floor.r, \
			cub3d->floor.g, cub3d->floor.b));
}

void	frame_calc(t_cub3d *cub3d)
{
	int				ct;
	int				ctt;
	t_math			*math;
	unsigned int	color;

	ct = -1;
	math = &(cub3d->math);
	while (++ct < WIDTH)
	{
		math->camera_x = 2 * ct / (double) WIDTH - 1;
		split_screen_two(cub3d, math);
		calculating_rays(cub3d, math);
		does_ray_hitting_wall(cub3d, math);
		calculating_drawing_screen_and_fisheye_ctl(cub3d, math);
		drawing_screen(cub3d, math);
		ctt = 0;
		painting(cub3d, ct, ctt, color);
	}
}
