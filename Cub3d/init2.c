/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:41:59 by okandemi          #+#    #+#             */
/*   Updated: 2023/10/07 17:53:20 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	color_ctl(t_cub3d *cub3d)
{
	int		i;
	char	c;

	i = -1;
	while (cub3d->map_info->c[++i] && cub3d->map_info->c[i] != '\n')
	{
		c = cub3d->map_info->c[i];
		if (c != ',' && !ft_isdigit(c))
			exit(printf("ERROR: WRONG MAP INFO\n"));
	}
	i = -1;
	while (cub3d->map_info->f[++i] && cub3d->map_info->f[i] != '\n')
	{
		c = cub3d->map_info->f[i];
		if (c && c != ',' && !ft_isdigit(c))
			exit(printf("ERROR: WRONG MAP INFO\n"));
	}
}

void	free_get_color(t_cub3d *cub3d, char **a)
{
	int	i;
	int	knt;

	i = 0;
	knt = 0;
	while (a[i])
		i++;
	if (a[i - 1][0] == 10)
		knt = 1;
	i = -1;
	while (a[++i] && !knt)
	{
		if (ft_atoi(a[i]) > 255 || ft_atoi(a[i]) < 0)
			knt = 1;
	}
	if (i != 3 || knt)
	{
		i = -1;
		while (a[++i])
			free(a[i]);
		free(a);
		exit(printf("ERROR: WRONG MAP INFO\n"));
	}
}

void	get_color(t_cub3d *cub3d)
{
	int		i;
	char	**a;

	a = ft_split(cub3d->map_info->f, ',');
	free_get_color(cub3d, a);
	cub3d->floor.r = ft_atoi(a[0]);
	cub3d->floor.g = ft_atoi(a[1]);
	cub3d->floor.b = ft_atoi(a[2]);
	i = -1;
	while (a[++i])
		free(a[i]);
	free(a);
	a = ft_split(cub3d->map_info->c, ',');
	free_get_color(cub3d, a);
	cub3d->sky.r = ft_atoi(a[0]);
	cub3d->sky.g = ft_atoi(a[1]);
	cub3d->sky.b = ft_atoi(a[2]);
	i = -1;
	while (a[++i])
		free(a[i]);
	free(a);
	color_ctl(cub3d);
}
