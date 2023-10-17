/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:22:21 by ydegerli          #+#    #+#             */
/*   Updated: 2023/10/07 16:02:23 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_cub3d_map(t_cub3d *cub3d)
{
	int	i;

	i = -1;
	while (cub3d->map[++i])
		free(cub3d->map[i]);
	free(cub3d->map);
}

void	err_data_ctl(char *str, t_cub3d *cub3d)
{
	free_map_info(cub3d);
	free(cub3d);
	printf("%s", str);
	exit (1);
}

void	err_plyr_ctrl(char *str, t_cub3d *cub3d)
{
	printf("%s", str);
	free_map_info(cub3d);
	free_cub3d_map(cub3d);
	free(cub3d);
	exit (1);
}

void	error_data_ctl(t_cub3d *cub3d)
{
	if (cub3d->fd < 3)
	{
		free(cub3d);
		exit (printf("ERROR: Map cannot open\n"));
	}
}

void	free_int_map(t_cub3d *cub3d)
{
	int	i;

	i = cub3d->line_count;
	while (--i >= 0)
		free(cub3d->int_map[i]);
	free(cub3d->int_map);
	free(cub3d->move);
	free(cub3d->mouse);
	free(cub3d->player);
}
