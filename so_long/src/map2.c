/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:49:20 by okandemi          #+#    #+#             */
/*   Updated: 2023/01/27 13:00:53 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_ber_extension(char *str, t_data *data)
{
	int	i;

	i = my_strlen(str);
	if (i > 4 && (str[i - 1] != 'r' || str[i - 2] != 'e' || str[i - 3] != 'b'
			|| str[i - 4] != '.'))
		error("Error! The map file must have .ber extension\n", data);
}

void	check_is_valid_map(t_data *data, int x, int y)
{
	char	*point;

	point = &data->tmp_map[y][x];
	if (*point == 'E')
		data->map_is_true = 1;
	if (*point != '1' && *point != 'E')
	{
		if (*point == 'C')
			data->tmp_number--;
		*point = '.';
		if (data->tmp_map[y][x + 1] != '1' && data->tmp_map[y][x + 1] != '.')
			check_is_valid_map(data, x + 1, y);
		if (data->tmp_map[y][x - 1] != '1' && data->tmp_map[y][x - 1] != '.')
			check_is_valid_map(data, x - 1, y);
		if (data->tmp_map[y + 1][x] != '1' && data->tmp_map[y + 1][x] != '.')
			check_is_valid_map(data, x, y + 1);
		if (data->tmp_map[y - 1][x] != '1' && data->tmp_map[y - 1][x] != '.')
			check_is_valid_map(data, x, y - 1);
	}
}

void	check_can_all_collectible(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map_y)
	{
		free(data->tmp_map[i]);
		i++;
	}
	free(data->tmp_map);
	if (data->tmp_number != 0)
		error("Error! The map is invalid! \
All collectibles must be collectible!\n", data);
	else if (data->map_is_true == 0)
		error("Error! The map is invalid! \
Player cannot reach to the exit in valid way!\n", data);
}

char	*ft_strdup(const char *str)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	i = 0;
	len = my_strlen(str);
	ptr = (char *)malloc(sizeof(char) * len +1);
	if (!ptr)
		return (NULL);
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			count;
	long int	tmp;

	tmp = n;
	count = 0;
	if (tmp == 0)
		return (ft_strdup("0"));
	while (tmp > 0)
	{
		tmp /= 10;
		count++;
	}
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	str[count--] = '\0';
	while (count >= 0)
	{
		str[count--] = (char)(n % 10) + '0';
		n /= 10;
	}
	return (str);
}
