/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:24:13 by ydegerli          #+#    #+#             */
/*   Updated: 2023/09/24 17:13:05 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_counter(long int n)
{
	long int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	if (n == 0)
	{
		return (1);
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			l;
	long int	tmp;

	tmp = n;
	l = digit_counter(tmp);
	str = (char *)malloc(l + 1);
	if (!str)
		return (NULL);
	str[l] = '\0';
	if (tmp < 0)
	{
		str[0] = '-';
		tmp = tmp * -1;
	}
	if (tmp == 0)
		str[0] = '0';
	while (tmp > 0)
	{
		str[--l] = (tmp % 10) + 48;
		tmp /= 10;
	}
	return (str);
}
