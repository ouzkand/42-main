/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:11:44 by okandemi          #+#    #+#             */
/*   Updated: 2022/10/28 14:21:16 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_control(char ch, va_list va)
{
	int	count;

	count = 0;
	if (ch == 'c')
		count += put_char(va_arg(va, int));
	else if (ch == 's')
		count += put_str(va_arg(va, char *));
	else if (ch == 'd' || ch == 'i')
		count += put_nbr(va_arg(va, int), 10, 0);
	else if (ch == 'u')
		count += put_nbr(va_arg(va, unsigned int), 10, 0);
	else if (ch == 'x')
		count += put_nbr(va_arg(va, unsigned int), 16, 0);
	else if (ch == 'X')
		count += put_nbr(va_arg(va, unsigned int), 16, 1);
	else if (ch == 'p')
		count += put_point(va_arg(va, unsigned long), 16, 0);
	else
		count += put_char('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	va;
	int		count;

	va_start(va, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			count += ft_control(*(str + 1), va);
			str++;
		}
		else
			count += put_char(*str);
		str++;
	}
	va_end(va);
	return (count);
}
