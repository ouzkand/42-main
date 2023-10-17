/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:39:48 by ydegerli          #+#    #+#             */
/*   Updated: 2022/10/20 16:15:20 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char) c)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}
/*#include <stdio.h>
int main ()
{
	char yusuf[] = "Bilgisayar";
	char g = 'g';
	printf("%p",ft_memchr(yusuf, g,10));
}*/
