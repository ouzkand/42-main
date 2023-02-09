/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:59:02 by okandemi          #+#    #+#             */
/*   Updated: 2023/02/04 16:56:13 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_a_len(char **argv, t_stack *data)
{
	int		i;
	int		j;
	char	*s;

	j = 1;
	while (argv[j])
	{
		s = argv[j];
		i = 0;
		while (s[i])
		{
			while (s[i] != '\0' && (s[i] == 32 || (s[i] >= 9 && s[i] <= 13)))
				i++;
			if (!s[i])
				break ;
			if (s[i] == '+' || s[i] == '-')
				i++;
			if (s[i] < '0' || s[i] > '9')
				error(data);
			while (s[i] && (s[i] >= '0' && s[i] <= '9'))
				i++;
			data->a_len++;
		}
		j++;
	}
}

void	error(t_stack *data)
{
	write (2, "Error\n", 6);
	ft_free(data);
	exit(EXIT_FAILURE);
}

void	ft_free(t_stack *data)
{
	if (data->a_s)
		free(data->a_s);
	if (data->b_s)
		free(data->b_s);
	if (data->sorted)
		free(data->sorted);
	if (data)
		free(data);
}

int	get_index(t_stack *data, int nbr)
{
	int	j;

	j = 0;
	while (j < data->len)
	{
		if (nbr == data->sorted[j])
			return (j);
		j++;
	}
	return (0);
}

void	max_bit(t_stack *data)
{
	int	max;

	max = data->a_len - 1;
	while (max > 0)
	{
		data->max_bit++;
		max /= 2;
	}
}
