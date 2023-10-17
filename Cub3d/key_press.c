/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:18:50 by okandemi          #+#    #+#             */
/*   Updated: 2023/10/07 16:02:52 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	red_x_close(int keycode, t_cub3d *cub3d)
{
	printf("Closed Successfully!\n");
	exit(0);
	return (0);
}

int	key_release(int keycode, t_cub3d *cub3d)
{
	if (keycode == W)
		cub3d->move->forward = 0;
	else if (keycode == S)
		cub3d->move->backward = 0;
	else if (keycode == A)
		cub3d->move->left = 0;
	else if (keycode == D)
		cub3d->move->right = 0;
	else if (keycode == L_AR)
		cub3d->move->rot_left = 0;
	else if (keycode == R_AR)
		cub3d->move->rot_right = 0;
	return (0);
}

void	run_esc(t_cub3d *cub3d)
{
	mlx_destroy_window(cub3d->mlx, cub3d->window);
	mlx_clear_window(cub3d->mlx, cub3d->window);
	printf("Closed Succesfully!\n");
	free_map_info(cub3d);
	free_int_map(cub3d);
	free_cub3d_map(cub3d);
	free(cub3d);
	exit (0);
}

int	key_press(int keycode, t_cub3d *cub3d)
{
	t_move	*move;

	move = cub3d->move;
	if (keycode == ESC)
		run_esc(cub3d);
	else if (keycode == W)
		move->forward = 1;
	else if (keycode == S)
		move->backward = 1;
	else if (keycode == A)
		move->left = 1;
	else if (keycode == D)
		move->right = 1;
	else if (keycode == L_AR)
		move->rot_left = 1;
	else if (keycode == R_AR)
		move->rot_right = 1;
	else if (keycode == PAUSE)
	{
		mlx_mouse_move(cub3d->window, WIDTH / 2, HEIGHT / 2);
		cub3d->lock = !cub3d->lock;
	}
	return (0);
}
