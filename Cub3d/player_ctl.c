/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_ctl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:59:24 by ydegerli          #+#    #+#             */
/*   Updated: 2023/10/07 17:57:04 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_newline_ctrl(t_cub3d *cub3d)
{
	int	i;

	i = -1;
	while (cub3d->file[++i] && cub3d->file[i + 1])
	{
		if (cub3d->file[i] == '\n' && cub3d->file[i + 1] == '\n')
		{
			while (cub3d->file[i] == '\n')
				i++;
			if (cub3d->file[i] != '\0')
			{
				printf("error: wrong map type\n");
				free_map_info(cub3d);
				free(cub3d->file);
				free(cub3d);
				exit(1);
			}
		}
	}
	cub3d->map = ft_split(cub3d->file, '\n');
	free(cub3d->file);
}

void	ft_char_ctrl(t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = -1;
	while (cub3d->map[++i])
	{
		j = -1;
		while (cub3d->map[i][++j])
		{
			if (!((cub3d->map[i][j] >= 9 && cub3d->map[i][j] <= 13) || \
				cub3d->map[i][j] == ' ') && \
				cub3d->map[i][j] != '0' && cub3d->map[i][j] != '1' && \
				cub3d->map[i][j] != 'N' && cub3d->map[i][j] != 'S' && \
				cub3d->map[i][j] != 'W' && cub3d->map[i][j] != 'E')
				err_plyr_ctrl("ERROR: Wrong character\n", cub3d);
		}
	}
}

void	ft_player_pos(t_cub3d *cub3d, int i, int j, int player_count)
{
	i = -1;
	while (cub3d->map[++i])
	{
		j = -1;
		while (cub3d->map[i][++j])
		{
			if (is_user_zero(cub3d->map[i][j]) && (j == 0 || i == 0 ||
				cub3d->map[i][j + 1] == '\0' || cub3d->map[i + 1] == NULL))
				err_plyr_ctrl("ERROR: Map is'nt close with walls!\n", cub3d);
			else if (is_user_zero(cub3d->map[i][j]) &&
				(cub3d->map[i][j - 1] == ' ' || cub3d->map[i][j + 1] == ' ' ||
				cub3d->map[i - 1][j] == ' ' || cub3d->map[i + 1][j] == ' '))
				err_plyr_ctrl("ERROR: Map is not close with walls!\n", cub3d);
			else if (is_user_zero(cub3d->map[i][j]) && (
				ft_strlen(cub3d->map[i - 1]) - 1 < j || \
				ft_strlen(cub3d->map[i + 1]) - 1 < j))
				err_plyr_ctrl("ERROR: Map is not close with walls!\n", cub3d);
			player_count = check_player(cub3d, i, j);
		}
	}
	if (player_count > 1 || player_count < 1)
		err_plyr_ctrl("ERROR: Players count not 1 on the map!\n", cub3d);
	ft_char_ctrl(cub3d);
}

void	ft_player_position_ctrl(t_cub3d *cub3d)
{
	int	i;
	int	j;
	int	player_count;

	ft_player_pos(cub3d, i, j, player_count);
}

char	*data_ctl(char *file_name, t_cub3d *cub3d)
{
	int	ct;

	ct = 0;
	cub3d->fd = open(file_name, O_RDONLY);
	error_data_ctl(cub3d);
	cub3d->map_info = ft_calloc(sizeof(t_MapInfo), 1);
	if (!cub3d->map_info)
		exit (printf("ERROR: MALLOC\n"));
	file_name = get_next_line(cub3d->fd);
	if (!file_name)
		exit(printf("ERROR: FILE DOES NOT FOUND\n"));
	while (1)
	{
		if (file_name && data_chck(file_name, cub3d) == 1)
			ct++;
		else if (!file_name || ft_strncmp(file_name, "\n", 1) != 0)
			break ;
		else if (ft_strncmp(file_name, "\n", 1) == 0)
			free(file_name);
		file_name = get_next_line(cub3d->fd);
	}
	if (ct != 6 || !file_name)
		err_data_ctl("ERROR! Wrong information in the map file!!!\n", cub3d);
	texture_ctl(cub3d);
	return (file_name);
}
