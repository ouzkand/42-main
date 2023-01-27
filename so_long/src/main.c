/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:44:47 by okandemi          #+#    #+#             */
/*   Updated: 2023/01/27 12:53:05 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	copy_maze(t_data *data)
{
	int		i;

	data->tmp_map = malloc(sizeof(char *) * (data->map_y + 1));
	i = 0;
	while (data->map[i])
	{	
		data->tmp_map[i] = ft_strdup(data->map[i]);
		i++;
	}
	data->tmp_map[i] = NULL;
}

void	init_image(t_data *data)
{
	data->player_fr = mlx_xpm_file_to_image(data->mlx, PL_FR,
			&data->imgx, &data->imgy);
	data->player_r = mlx_xpm_file_to_image(data->mlx, PL_RIGHT,
			&data->imgx, &data->imgy);
	data->player_l = mlx_xpm_file_to_image(data->mlx, PL_LEFT,
			&data->imgx, &data->imgy);
	data->player_b = mlx_xpm_file_to_image(data->mlx, PL_BACK,
			&data->imgx, &data->imgy);
	data->wall = mlx_xpm_file_to_image(data->mlx, WALL,
			&data->imgx, &data->imgy);
	data->grnd = mlx_xpm_file_to_image(data->mlx, GROUND,
			&data->imgx, &data->imgy);
	data->collectible = mlx_xpm_file_to_image(data->mlx, COLLECTIBLE,
			&data->imgx, &data->imgy);
	data->exit = mlx_xpm_file_to_image(data->mlx, EXIT,
			&data->imgx, &data->imgy);
	data->curr_pos = 'F';
	data->window = mlx_new_window(data->mlx, data->map_x * 64, data->map_y * 64,
			"so_long");
	put_image(data);
}

void	put_image(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->map_y * 64)
	{
		if (data->map[y / 64][x / 64] != '1'
			&& data->map[y / 64][x / 64] != '0')
			mlx_put_image_to_window(data->mlx, data->window, data->grnd, x, y);
		if (data->map[y / 64][x / 64] == '1')
			mlx_put_image_to_window(data->mlx, data->window, data->wall, x, y);
		else if (data->map[y / 64][x / 64] == '0')
			mlx_put_image_to_window(data->mlx, data->window, data->grnd, x, y);
		else if (data->map[y / 64][x / 64] == 'E')
			mlx_put_image_to_window(data->mlx, data->window, data->exit, x, y);
		else if (data->map[y / 64][x / 64] == 'C')
			mlx_put_image_to_window(data->mlx, data->window,
				data->collectible, x, y);
		else if (data->map[y / 64][x / 64] == 'P')
			put_image_player(data, x, y);
		x_y_operation(&x, &y, data);
	}
	score(data);
}

void	put_image_player(t_data *data, int x, int y)
{
	if (data->curr_pos == 'F')
		mlx_put_image_to_window(data->mlx, data->window, data->player_fr, x, y);
	else if (data->curr_pos == 'R')
		mlx_put_image_to_window(data->mlx, data->window, data->player_r, x, y);
	else if (data->curr_pos == 'L')
		mlx_put_image_to_window(data->mlx, data->window, data->player_l, x, y);
	else if (data->curr_pos == 'B')
		mlx_put_image_to_window(data->mlx, data->window, data->player_b, x, y);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 2)
	{
		data = ft_calloc(sizeof(t_data), 1);
		check_image(data);
		check_ber_extension(argv[1], data);
		make_map(data, argv[1]);
		check_map_wall(data);
		check_components(data);
		copy_maze(data);
		check_is_valid_map(data, data->player_x, data->player_y);
		check_can_all_collectible(data);
		data->mlx = mlx_init();
		init_image(data);
		mlx_hook(data->window, 2, 1L << 0, key_event, data);
		mlx_hook(data->window, 17, 1L << 2, close_window, data);
		mlx_loop(data->mlx);
	}
	else
		write (1, "Error! There must be 2 arguments\n", 34);
	return (0);
}
