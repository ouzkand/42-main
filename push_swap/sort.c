/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:16:19 by okandemi          #+#    #+#             */
/*   Updated: 2023/02/09 15:43:56 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_sort(t_stack *data)
{
	array_sort(data);
	if (data->a_len == 2)
		swap_a(data);
	else if (data->a_len == 3)
		three(data);
	else if (data->a_len == 5)
		five(data);
	else if (data->a_len > 5 || data->a_len == 4)
	{
		max_bit(data);
		radix(data);
	}
}

void	three(t_stack *data)
{
	if (data->a_s[0] > data->a_s[1] && data->a_s[0] > data->a_s[2] && \
		data->a_s[1] > data->a_s[2])
	{
		swap_a(data);
		revrotate_a(data);
	}
	else if (data->a_s[0] > data->a_s[1] && data->a_s[0] > data->a_s[2] && \
		data->a_s[1] < data->a_s[2])
		rotate_a(data);
	else if (data->a_s[1] > data->a_s[0] && data->a_s[1] > data->a_s[2] && \
		data->a_s[0] < data->a_s[2])
	{
		revrotate_a(data);
		swap_a(data);
	}
	else if (data->a_s[1] > data->a_s[0] && data->a_s[1] > data->a_s[2] && \
		data->a_s[0] > data->a_s[2])
		revrotate_a(data);
	else if (data->a_s[2] > data->a_s[0] && data->a_s[2] > data->a_s[1] && \
		data->a_s[0] > data->a_s[1])
		swap_a(data);
}

void	five(t_stack *data)
{
	while (data->sorted[2] <= data->a_s[0])
		rotate_a(data);
	if (data->sorted[2] > data->a_s[0])
		push_b(data);
	while (data->sorted[2] <= data->a_s[0])
		rotate_a(data);
	if (data->sorted[2] > data->a_s[0])
		push_b(data);
	three(data);
	if (data->b_s[1] > data->b_s[0])
		swap_b(data);
	push_a(data);
	push_a(data);
}

void	array_sort(t_stack *data)
{
	int	i;
	int	j;
	int	tmp;

	data->sorted = ft_calloc(sizeof(int), data->a_len);
	i = -1;
	while (++i < data->a_len)
		data->sorted[i] = data->a_s[i];
	i = 0;
	while (i < (data->a_len - 1))
	{
		j = i + 1;
		while (j < data->a_len)
		{
			if (data->sorted[i] > data->sorted[j])
			{	
				tmp = data->sorted[i];
				data->sorted[i] = data->sorted[j];
				data->sorted[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	radix(t_stack *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->max_bit)
	{
		j = 0;
		while (j < data->len)
		{
			if (get_index(data, data->a_s[0]) >> i & 1)
				rotate_a(data);
			else
				push_b(data);
			j++;
		}
		while (data->b_len)
			push_a(data);
		i++;
	}
}
