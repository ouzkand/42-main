/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:11:59 by okandemi          #+#    #+#             */
/*   Updated: 2023/10/03 19:07:51 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_cub3d *cub3d)
{
	if (cub3d->int_map[(int)cub3d->player->y][(int)(cub3d->player->x + \
		(cub3d->player->dir_x * cub3d->move->speed))] == 0)
		cub3d->player->x += (double) cub3d->player->dir_x * cub3d->move->speed;
	if (cub3d->int_map[(int)(cub3d->player->y - (cub3d->player->dir_y * \
		cub3d->move->speed))][(int) cub3d->player->x] == 0)
		cub3d->player->y -= (double) cub3d->player->dir_y * cub3d->move->speed;
}

void	move_back(t_cub3d *cub3d)
{
	if (cub3d->int_map[(int)cub3d->player->y][(int)(cub3d->player->x - \
		(cub3d->player->dir_x * cub3d->move->speed))] == 0)
		cub3d->player->x -= (double) cub3d->player->dir_x * cub3d->move->speed;
	if (cub3d->int_map[(int)(cub3d->player->y + (cub3d->player->dir_y * \
		cub3d->move->speed))][(int)cub3d->player->x] == 0)
		cub3d->player->y += (double) cub3d->player->dir_y * cub3d->move->speed;
}

void	move_left(t_cub3d *cub3d)
{
	if (cub3d->int_map[(int)cub3d->player->y][(int)(cub3d->player->x - \
		(cub3d->player->dir_y * cub3d->move->speed))] == 0)
		cub3d->player->x -= (double) cub3d->player->dir_y * cub3d->move->speed;
	if (cub3d->int_map[(int)(cub3d->player->y - (cub3d->player->dir_x * \
		cub3d->move->speed))][(int)cub3d->player->x] == 0)
		cub3d->player->y -= (double) cub3d->player->dir_x * cub3d->move->speed;
}

void	move_right(t_cub3d *cub3d)
{
	if (cub3d->int_map[(int)cub3d->player->y][(int)(cub3d->player->x + \
		(cub3d->player->dir_y * cub3d->move->speed))] == 0)
		cub3d->player->x += (double) cub3d->player->dir_y * cub3d->move->speed;
	if (cub3d->int_map[(int)(cub3d->player->y + (cub3d->player->dir_x * \
		cub3d->move->speed))][(int) cub3d->player->x] == 0)
		cub3d->player->y += (double) cub3d->player->dir_x * cub3d->move->speed;
}

void	rot_left(t_cub3d *cub3d)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub3d->player->dir_x;
	old_plane_x = cub3d->player->plane_x;
	cub3d->player->dir_x = cub3d->player->dir_x * cos(cub3d->move->rot_speed) - \
		cub3d->player->dir_y * sin(cub3d->move->rot_speed);
	cub3d->player->dir_y = old_dir_x * sin(cub3d->move->rot_speed) + \
		cub3d->player->dir_y * cos(-cub3d->move->rot_speed);
	cub3d->player->plane_x = cub3d->player->plane_x * \
		cos(cub3d->move->rot_speed) - cub3d->player->plane_y * \
		sin(cub3d->move->rot_speed);
	cub3d->player->plane_y = old_plane_x * sin(cub3d->move->rot_speed) + \
		cub3d->player->plane_y * cos(-cub3d->move->rot_speed);
}
