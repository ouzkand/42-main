/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:46:52 by ydegerli          #+#    #+#             */
/*   Updated: 2022/10/20 15:59:48 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)

{
	if ((dst == 0) && (src == 0))
		return (0);
	if (dst <= src)
	{
		ft_memcpy(dst, src, len);
	}
	else
	{
		while (len > 0)
		{
			((unsigned char *)dst)[len - 1] = ((unsigned char *)src)[len - 1];
			len--;
		}
	}
	return (dst);
}
/*#include <stdio.h>
int main ()
{
	char yusuf[] = "YusufDegerli";
	char taha[] = "sdkfgajf";
	printf("%s", ft_memmove(yusuf, taha, 5));
}*/
