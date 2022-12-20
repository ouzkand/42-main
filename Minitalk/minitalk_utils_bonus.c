/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:05:59 by okandemi          #+#    #+#             */
/*   Updated: 2022/12/19 12:47:46 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_count(long int tmp)
{
	int	count;

	count = 0;
	if (tmp == 0)
		return (1);
	if (tmp < 0)
	{
		count++;
		tmp = -tmp;
	}
	while (tmp > 0)
	{
		tmp /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			count;
	int			i;
	long int	tmp;

	tmp = n;
	count = ft_count(tmp);
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	str[count--] = '\0';
	i = 0;
	if (n < 0)
	{
		tmp = -tmp;
		str[0] = '-';
		i++;
	}
	while (count >= i)
	{
		str[count] = (char)(tmp % 10) + '0';
		tmp /= 10;
		count--;
	}
	return (str);
}

int	ft_atoi(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i = (i * 10) + (*str - '0');
		str++;
	}
	return (i);
}
