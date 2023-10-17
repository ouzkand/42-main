/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:04:59 by ydegerli          #+#    #+#             */
/*   Updated: 2022/10/20 15:58:36 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*csrc;
	unsigned char	*cdest;

	i = 0;
	csrc = (unsigned char *)src;
	cdest = (unsigned char *)dst;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)cdest)[i] = csrc[i];
		i++;
	}
	return (dst);
}
/*
#include <stdio.h>
int main ()
{
	char yusuf[] = "YusgjcıDegerli";
	char taha[] = "Yusuferik";
	printf("%s", ft_memcpy(yusuf, taha, 5));
}*/
