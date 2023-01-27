/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:43:49 by okandemi          #+#    #+#             */
/*   Updated: 2023/01/27 12:59:07 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *str, t_data *data)
{
	ft_printf("%s", str);
	free_all(data);
	exit(EXIT_FAILURE);
}

void	free_all(t_data *data)
{
	int		i;

	i = 0;
	if (data->map)
	{
		while (i < data->map_y && data->map[i])
			free(data->map[i++]);
		free(data->map);
	}
	if (data->mlx)
		free_all_2(data);
	free(data);
}

void	free_all_2(t_data *data)
{
	mlx_destroy_image(data->mlx, data->player_fr);
	mlx_destroy_image(data->mlx, data->player_r);
	mlx_destroy_image(data->mlx, data->player_l);
	mlx_destroy_image(data->mlx, data->player_b);
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->collectible);
	mlx_destroy_image(data->mlx, data->grnd);
	mlx_destroy_image(data->mlx, data->exit);
	mlx_destroy_image(data->mlx, data->window);
}

int	close_window(t_data *data)
{
	free_all(data);
	exit(EXIT_SUCCESS);
	return (0);
}

void	check_image(t_data *data)
{
	if ((0 > open(PL_BACK, O_RDONLY)) || (0 > open(PL_FR, O_RDONLY))
		|| (0 > open(PL_LEFT, O_RDONLY)) || (0 > open(PL_RIGHT, O_RDONLY))
		|| (0 > open(EXIT, O_RDONLY)) || (0 > open(GROUND, O_RDONLY))
		|| (0 > open(WALL, O_RDONLY)) || (0 > open(COLLECTIBLE, O_RDONLY)))
		error("Error, (image) not found!", data);
}
