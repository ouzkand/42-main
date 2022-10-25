/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:02:00 by okandemi          #+#    #+#             */
/*   Updated: 2022/10/13 17:04:29 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*string;
	int		i;

	if (!s)
		return ((char *)s);
	i = 0;
	string = ft_strdup(s);
	if (!string)
		return (NULL);
	while (string[i])
	{
		string[i] = f(i, string[i]);
		i++;
	}
	return (string);
}
