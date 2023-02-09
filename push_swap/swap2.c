/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:42:59 by okandemi          #+#    #+#             */
/*   Updated: 2023/02/01 14:56:55 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_push(int *d, int len)
{
	while (len > 0)
	{
		d[len] = d[len - 1];
		len--;
	}
}

void	ft_pop(int *d, int len)
{
	int	i;

	i = 0;
	while (i < (len - 1))
	{
		d[i] = d[i + 1];
		i++;
	}
}

void	push_a(t_stack *data)
{
	if (data->b_len > 0)
	{
		ft_push(data->a_s, data->a_len);
		data->a_len++;
		data->a_s[0] = data->b_s[0];
		ft_pop(data->b_s, data->b_len);
		data->b_len--;
	}
	else
		return ;
	write(1, "pa\n", 3);
}

void	push_b(t_stack *data)
{
	if (data->a_len > 0)
	{
		ft_push(data->b_s, data->b_len);
		data->b_len++;
		data->b_s[0] = data->a_s[0];
		ft_pop(data->a_s, data->a_len);
		data->a_len--;
	}
	else
		return ;
	write(1, "pb\n", 3);
}

void	rotate_b(t_stack *data)
{
	int	tmp;
	int	len;

	if (data->b_len > 1)
	{
		tmp = data->b_s[0];
		len = 0;
		while (++len < data->b_len)
			data->b_s[len - 1] = data->b_s[len];
		data->b_s[len - 1] = tmp;
		write (1, "rb\n", 3);
	}
}
