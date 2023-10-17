/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:23:00 by ydegerli          #+#    #+#             */
/*   Updated: 2023/10/07 18:30:50 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	data_chck(char *file_name, t_cub3d *cub3d)
{
	if (!cub3d->map_info->west && ft_strncmp(file_name, "WE ", 3) == 0)
		cub3d->map_info->west = file_name;
	else if (!cub3d->map_info->south && ft_strncmp(file_name, "SO ", 3) == 0)
		cub3d->map_info->south = file_name;
	else if (!cub3d->map_info->north && ft_strncmp(file_name, "NO ", 3) == 0)
		cub3d->map_info->north = file_name;
	else if (!cub3d->map_info->east && ft_strncmp(file_name, "EA ", 3) == 0)
		cub3d->map_info->east = file_name;
	else if (!cub3d->map_info->c && ft_strncmp(file_name, "C ", 2) == 0 \
	&& ft_isdigit(file_name[2]))
		cub3d->map_info->c = file_name;
	else if (!cub3d->map_info->f && ft_strncmp(file_name, "F ", 2) == 0 \
	&& ft_isdigit(file_name[2]))
		cub3d->map_info->f = file_name;
	else
		return (0);
	return (1);
}

void	rebuild_map(char *file_name, t_cub3d *cub3d)
{
	char	*tmp;

	cub3d->file = ft_strdup("");
	while (file_name)
	{
		if (file_name[0])
		{
			tmp = cub3d->file;
			cub3d->file = ft_strjoin(cub3d->file, file_name);
			free (tmp);
			free (file_name);
		}
		file_name = get_next_line(cub3d->fd);
	}
	ft_newline_ctrl(cub3d);
	ft_player_position_ctrl(cub3d);
}

int	lock_cntrl(t_cub3d *cub3d)
{
	mlx_put_image_to_window(cub3d->mlx, cub3d->window, \
		cub3d->image.images, 0, 0);
	if (cub3d->lock)
	{
		mlx_mouse_show();
		draw_pause(cub3d, 0x00AAFF);
		return (1);
	}
	mlx_mouse_hide();
	if ((cub3d->move->forward || cub3d->move->backward) \
		&& (cub3d->move->left || cub3d->move->right))
		cub3d->move->speed = 0.06 / sqrt(2);
	else
		cub3d->move->speed = 0.06;
	return (0);
}

int	ft_loop(t_cub3d *cub3d)
{
	if (lock_cntrl(cub3d))
		return (0);
	mlx_mouse_get_pos(cub3d->window, &(cub3d->mouse->pos_x), \
		&(cub3d->mouse->pos_y));
	if (cub3d->mouse->pos_x - cub3d->mouse->old_pos_x != 0)
		rotate_with_mouse(cub3d);
	cub3d->mouse->old_pos_x = WIDTH / 2;
	cub3d->mouse->old_pos_y = HEIGHT / 2;
	cub3d->mouse->pos_x = WIDTH / 2;
	cub3d->mouse->pos_y = HEIGHT / 2;
	move(cub3d);
	frame_calc(cub3d);
	draw_maze(cub3d);
	put_mini_map_red_dot(cub3d, 0xFF0000);
	return (1);
}

void	init(t_cub3d *cub3d, char *av)
{
	cub3d = (t_cub3d *) ft_calloc(sizeof(t_cub3d), 1);
	if (!(cub3d))
		exit(printf("ERROR: MALLOC\n"));
	map_ctl(av, cub3d);
	cub3d->mlx = mlx_init();
	cub3d->window = mlx_new_window(cub3d->mlx, WIDTH, HEIGHT, "Cub3D");
	get_color(cub3d);
	taking_pics(cub3d);
	cub3d->length_x = (WIDTH / 3) / cub3d->max_line;
	cub3d->length_y = (HEIGHT / 3) / cub3d->line_count;
	cub3d->move->rot_speed = (double) 0.04;
	cub3d->mouse->old_pos_x = WIDTH / 2;
	cub3d->mouse->old_pos_y = HEIGHT / 2;
	mlx_mouse_move(cub3d->window, WIDTH / 2, HEIGHT / 2);
	mlx_mouse_hide();
	cub3d->image.images = mlx_new_image(cub3d->mlx, WIDTH, HEIGHT);
	cub3d->image.data = mlx_get_data_addr(cub3d->image.images, \
		&(cub3d->image.bpp), &(cub3d->image.sizeline), &(cub3d->image.endian));
	draw_image(cub3d);
	mlx_hook(cub3d->window, 2, 0, key_press, cub3d);
	mlx_hook(cub3d->window, 3, 0, key_release, cub3d);
	mlx_hook(cub3d->window, 17, 1L << 2, red_x_close, cub3d);
	mlx_loop_hook(cub3d->mlx, &ft_loop, cub3d);
	mlx_loop(cub3d->mlx);
}
