/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:29:54 by okandemi          #+#    #+#             */
/*   Updated: 2022/10/21 12:29:56 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	strlen;

	strlen = ft_strlen(str);
	while (strlen >= 0)
	{
		if (str[strlen] == (char)c)
			return ((char *)&str[strlen]);
		strlen--;
	}
	return (NULL);
}
