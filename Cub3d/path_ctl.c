/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_ctl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:10:17 by ydegerli          #+#    #+#             */
/*   Updated: 2023/10/07 16:03:56 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_user(char c)
{
	if ((c == 'N') || (c == 'S') || (c == 'W') || (c == 'E'))
		return (1);
	return (0);
}

void	convert_map(t_cub3d *cub3d)
{
	int	i;
	int	j;

	cub3d->int_map = (int **)ft_calloc(sizeof(int **), cub3d->line_count);
	if (!cub3d->int_map)
		exit(printf("ERROR: MALLOC\n"));
	i = -1;
	while (++i < cub3d->line_count)
	{
		cub3d->int_map[i] = (int *)ft_calloc(sizeof(int *), (cub3d->max_line));
		if (!cub3d->int_map[i])
			exit(printf("ERROR: MALLOC\n"));
		j = -1;
		while (cub3d->map[i][++j])
		{
			if (cub3d->map[i][j] == '0')
				cub3d->int_map[i][j] = 0;
			else if (is_user(cub3d->map[i][j]))
				set_user(cub3d, i, j);
			else
				cub3d->int_map[i][j] = 1;
		}
		while (j <= cub3d->max_line)
			cub3d->int_map[i][j++] = 1;
	}
}

void	map_char_to_int(t_cub3d *cub3d)
{
	find_longest_line(cub3d);
	find_line_count(cub3d);
	convert_map(cub3d);
}

void	map_ctl(char *file_name, t_cub3d *cub3d)
{
	int	len;

	len = 0;
	file_name = data_ctl(file_name, cub3d);
	rebuild_map(file_name, cub3d);
	cub3d->move = (t_move *) ft_calloc(sizeof(t_move), 1);
	if (!cub3d->move)
		exit(printf("ERROR: MALLOC\n"));
	cub3d->player = (t_player *) ft_calloc(sizeof(t_player), 1);
	if (!cub3d->player)
		exit(printf("ERROR: MALLOC\n"));
	cub3d->mouse = (t_mouse *) ft_calloc(sizeof(t_mouse), 1);
	if (!cub3d->mouse)
		exit(printf("ERROR: MALLOC\n"));
	map_char_to_int(cub3d);
}
