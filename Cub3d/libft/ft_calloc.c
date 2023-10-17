/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:35:19 by ydegerli          #+#    #+#             */
/*   Updated: 2022/10/20 16:20:55 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * count);
	return (ptr);
}
/*#include <stdio.h>
int main ()
{
	int *ip, id;

	ip = (int *) ft_calloc(10, sizeof(int));

	for (id=0; id<10;id++)
	{
		*(ip+id) = (id+1) * 5;
		printf("%p adresindeki değer:  %d\n", (ip+id), *(ip+id));
	}
	free(ip);
}*/
