/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:05:36 by okandemi          #+#    #+#             */
/*   Updated: 2023/01/23 11:47:24 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	x_y_operation(int *x, int *y, t_data *data)
{
	if (*x == data->map_x * 64)
	{
		*y += 64;
		*x = -64;
	}
	*x += 64;
}

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(num * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (num * size));
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*((unsigned char *) b + i) = c;
		i++;
	}
	return (b);
}

size_t	my_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
