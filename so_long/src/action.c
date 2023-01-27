/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:32:51 by okandemi          #+#    #+#             */
/*   Updated: 2023/01/24 12:53:26 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_event(int keycode, t_data *data)
{
	if (keycode == 13)
		move(data, 0, -1, 'B');
	else if (keycode == 1)
		move(data, 0, 1, 'F');
	else if (keycode == 2)
		move(data, 1, 0, 'R');
	else if (keycode == 0)
		move(data, -1, 0, 'L');
	else if (keycode == 53)
		close_window(data);
	return (0);
}

void	move(t_data *data, int x, int y, char c)
{
	if (is_valid_movement(data, data->player_x + x, data->player_y + y))
	{
		data->map[data->player_y][data->player_x] = '0';
		data->player_y += y;
		data->player_x += x;
		data->map[data->player_y][data->player_x] = 'P';
		data->curr_pos = c;
		render_after_move(data);
	}
}

int	is_valid_movement(t_data *data, int x, int y)
{
	if (data->map[y][x] != '1')
	{
		if (data->map[y][x] == 'C')
		{
			data->gold_nbr--;
			data->map[y][x] = '0';
		}
		else if (data->map[y][x] == 'E' && data->gold_nbr != 0)
			return (0);
		else if (!data->gold_nbr && data->map[y][x] == 'E')
		{
			ft_printf("Moves: %d\nCongrats!\n", ++data->move_count);
			close_window(data);
			return (1);
		}
		ft_printf("Moves: %d\n", ++data->move_count);
		return (1);
	}
	return (0);
}

void	render_after_move(t_data *data)
{
	mlx_clear_window(data->mlx, data->window);
	put_image(data);
}

void	score(t_data *data)
{
	data->move_scrn = ft_itoa(data->move_count);
	mlx_string_put(data->mlx, data->window, 5, 30, 0xFFFFFF, "Moves: ");
	mlx_string_put(data->mlx, data->window, 50, 30, 0xbe00ff, data->move_scrn);
	free(data->move_scrn);
}
