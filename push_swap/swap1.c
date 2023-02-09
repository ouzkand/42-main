/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:35:49 by okandemi          #+#    #+#             */
/*   Updated: 2023/01/31 12:35:49 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_a(t_stack *data)
{
	int	tmp;

	if (data->a_len >= 2)
	{
		tmp = data->a_s[0];
		data->a_s[0] = data->a_s[1];
		data->a_s[1] = tmp;
		write(1, "sa\n", 3);
	}
	else
		return ;
}

void	swap_b(t_stack *data)
{
	int	tmp;

	if (data->b_len >= 2)
	{
		tmp = data->b_s[0];
		data->b_s[0] = data->b_s[1];
		data->b_s[1] = tmp;
		write(1, "sb\n", 3);
	}
	else
		return ;
}

void	revrotate_a(t_stack *data)
{
	int	tmp;
	int	i;

	if (data->a_len > 1)
	{
		tmp = data->a_s[data->a_len - 1];
		i = data->a_len;
		while (--i >= 0)
			data->a_s[i] = data->a_s[i - 1];
		data->a_s[0] = tmp;
		write (1, "rra\n", 4);
	}
}

void	revrotate_b(t_stack *data)
{
	int	tmp;
	int	i;

	if (data->b_len > 1)
	{
		tmp = data->b_s[data->b_len - 1];
		i = data->b_len;
		while (--i >= 0)
			data->b_s[i] = data->b_s[i - 1];
		data->b_s[0] = tmp;
		write (1, "rrb\n", 4);
	}
}

void	rotate_a(t_stack *data)
{
	int	tmp;
	int	len;

	if (data->a_len > 1)
	{
		tmp = data->a_s[0];
		len = 0;
		while (++len < data->a_len)
			data->a_s[len - 1] = data->a_s[len];
		data->a_s[len - 1] = tmp;
		write (1, "ra\n", 3);
	}
}
