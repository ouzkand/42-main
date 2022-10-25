/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:27:26 by okandemi          #+#    #+#             */
/*   Updated: 2022/10/21 12:27:50 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_max(long int n)
{
	if ((n) > 2147483647)
		return (-1);
	else if ((n) < -2147483648)
		return (0);
	else
		return (1);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	result;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] && (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == 32))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ((str[i] <= '9' && str[i] >= '0') && str[i])
	{
		result = result * 10 + (str[i] - '0');
		if (ft_max(sign * result) != 1)
			return (ft_max(result * sign));
		i++;
	}
	return (result * sign);
}
