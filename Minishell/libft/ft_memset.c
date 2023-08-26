/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:03:27 by okandemi          #+#    #+#             */
/*   Updated: 2023/07/19 17:03:29 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*metin;
	unsigned char	test;
	size_t			i;

	i = 0;
	metin = (unsigned char *) b;
	test = (unsigned char)c;
	while (i < len)
	{
		metin[i] = test;
		i++;
	}
	return (b);
}
