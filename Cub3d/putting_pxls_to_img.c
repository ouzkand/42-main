/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putting_pxls_to_img.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:15:58 by okandemi          #+#    #+#             */
/*   Updated: 2023/10/07 18:07:01 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	delete_new_line(t_cub3d *cub3d)
{
	char	*tmp;

	tmp = ft_strtrim(cub3d->map_info->north, "\n");
	free(cub3d->map_info->north);
	cub3d->map_info->north = tmp;
	tmp = ft_strtrim(cub3d->map_info->south, "\n");
	free(cub3d->map_info->south);
	cub3d->map_info->south = tmp;
	tmp = ft_strtrim(cub3d->map_info->west, "\n");
	free(cub3d->map_info->west);
	cub3d->map_info->west = tmp;
	tmp = ft_strtrim(cub3d->map_info->east, "\n");
	free(cub3d->map_info->east);
	cub3d->map_info->east = tmp;
}

void	taking_pics(t_cub3d *cub3d)
{
	delete_new_line(cub3d);
	cub3d->north.images = mlx_xpm_file_to_image(cub3d->mlx,
			cub3d->map_info->north, &(cub3d->north.w), &(cub3d->north.h));
	cub3d->south.images = mlx_xpm_file_to_image(cub3d->mlx,
			cub3d->map_info->south, &(cub3d->south.w), &(cub3d->south.h));
	cub3d->west.images = mlx_xpm_file_to_image(cub3d->mlx,
			cub3d->map_info->west, &(cub3d->west.w), &(cub3d->west.h));
	cub3d->east.images = mlx_xpm_file_to_image(cub3d->mlx,
			cub3d->map_info->east, &(cub3d->east.w), &(cub3d->east.h));
	if (!cub3d->north.images || !cub3d->south.images
		|| !cub3d->west.images || !cub3d->east.images)
		exit(printf("ERROR: IMAGE DOES NOT OPEN\n"));
	cub3d->north.data = mlx_get_data_addr(cub3d->north.images, \
		&(cub3d->north.bpp), &(cub3d->north.sizeline), &(cub3d->north.endian));
	cub3d->south.data = mlx_get_data_addr(cub3d->south.images, \
		&(cub3d->south.bpp), &(cub3d->south.sizeline), &(cub3d->south.endian));
	cub3d->west.data = mlx_get_data_addr(cub3d->west.images, \
		&(cub3d->west.bpp), &(cub3d->west.sizeline), &(cub3d->west.endian));
	cub3d->east.data = mlx_get_data_addr(cub3d->east.images, \
		&(cub3d->east.bpp), &(cub3d->east.sizeline), &(cub3d->east.endian));
}

void	draw_image(t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT)
			mlx_pixel_put(cub3d->mlx, cub3d->image.images, i, j, 0x0000FF);
	}
}

void	texture_ctl(t_cub3d *cub3d)
{
	char	*tmp;

	tmp = cub3d->map_info->north;
	cub3d->map_info->north = ft_strtrim(tmp, "NO ");
	free(tmp);
	tmp = cub3d->map_info->south;
	cub3d->map_info->south = ft_strtrim(tmp, "SO ");
	free(tmp);
	tmp = cub3d->map_info->east;
	cub3d->map_info->east = ft_strtrim(tmp, "EA ");
	free(tmp);
	tmp = cub3d->map_info->west;
	cub3d->map_info->west = ft_strtrim(tmp, "WE ");
	free(tmp);
	tmp = cub3d->map_info->c;
	cub3d->map_info->c = ft_strtrim(tmp, "C ");
	free(tmp);
	tmp = cub3d->map_info->f;
	cub3d->map_info->f = ft_strtrim(tmp, "F ");
	free(tmp);
	text_len(cub3d);
}
