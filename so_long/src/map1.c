/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:31:07 by okandemi          #+#    #+#             */
/*   Updated: 2023/01/23 17:56:45 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_x_y(t_data *data, char *file)
{
	int		fd;
	char	*str;

	fd = open(file, O_RDONLY);
	while (1)
	{	
		str = get_next_line(fd);
		if (!str)
			break ;
		data->map_y++;
		data->map_x = my_strlen(str);
		free(str);
	}
	close(fd);
}

void	make_map(t_data *data, char *file)
{
	int		fd;
	int		i;
	char	*str;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error("Error! File not found!\n", data);
	map_x_y(data, file);
	data->map = ft_calloc(sizeof(char *), (data->map_y + 1));
	i = 0;
	while (i < data->map_y)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		data->map[i] = ft_strdup(str);
		if (i++ < data->map_y)
		{
			if (data->map_x != ft_strlen(str))
				error("Error! The map must be rectangular!\n", data);
		}
		free(str);
	}
	data->map[data->map_y] = NULL;
	close(fd);
}

void	check_map_wall(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map_y)
	{
		if (data->map[i][0] != '1' || data->map[i++][data->map_x - 1] != '1')
			error("Error! The map must be surrounded by walls!\n", data);
	}
	i = 0;
	while (i < data->map_x)
	{
		if (data->map[0][i] != '1' || data->map[data->map_y - 1][i++] != '1')
			error("Error! The map must be surrounded by walls!\n", data);
	}
}

void	check_components(t_data *data)
{
	static int		p = 0;
	static int		c = 0;
	static int		e = 0;

	check_atleast(data, &p, &e, &c);
	if (p != 1 || e != 1 || c <= 0)
		error("Error! The map must contain 1 exit, 1 starting position\
	and at least 1 collectible!\n", data);
	else
	{
		data->gold_nbr = c;
		data->tmp_number = data->gold_nbr;
	}
}

void	check_atleast(t_data *data, int *p, int *e, int *c)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->map_y)
	{
		j = 0;
		while (j < data->map_x)
		{
			if (data->map[i][j] == 'P')
			{
				(*p)++;
				data->player_x = j;
				data->player_y = i;
			}
			else if (data->map[i][j] == 'C')
				(*c)++;
			else if (data->map[i][j] == 'E')
				(*e)++;
			else if (data->map[i][j] != '1' && data->map[i][j] != '0')
				error("Error! The map must include only \
/'P'/'E'/'C'/'1'/'0'/\n", data);
			j++;
		}
		i++;
	}
}
