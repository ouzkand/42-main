/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:04:41 by okandemi          #+#    #+#             */
/*   Updated: 2023/07/19 17:06:30 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_malloc_if(char const *s, unsigned int start, size_t len)
{
	size_t	i;

	i = ft_strlen(s);
	if (i - start >= len)
		return (len);
	else
		return (i - start);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s || start > ft_strlen(s) || len > 2147483647)
		return (ft_strdup(""));
	str = malloc(sizeof(char) * (ft_malloc_if(s, start, len) + 1));
	if (!str)
		return (NULL);
	while (i < len && s[start])
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
