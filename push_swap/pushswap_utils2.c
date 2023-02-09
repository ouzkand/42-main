/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:44:49 by okandemi          #+#    #+#             */
/*   Updated: 2023/02/04 16:45:31 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
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

void	my_atoi(const char *s, t_stack *data)
{
	int		sign;
	long	result;
	long	i;

	i = 0;
	while (s[i])
	{
		sign = 1;
		result = 0;
		while (s[i] != '\0' && (s[i] == 32 || (s[i] >= 9 && s[i] <= 13)))
			i++;
		if (!s[i])
			break ;
		if (s[i] == '+' || s[i] == '-')
		{
			if (s[i++] == '-')
				sign = sign * (-1);
		}
		if (s[i] < '0' || s[i] > '9')
			error(data);
		while (s[i] && (s[i] >= '0' && s[i] <= '9'))
			result = result * 10 + (s[i++] - '0');
		max_control((result * sign), data);
		data->a_s[data->b_len++] = result * sign;
	}
}

void	max_control(long int result, t_stack *data)
{
	if (result > INT_MAX || result < INT_MIN)
		error(data);
}
