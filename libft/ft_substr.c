/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:30:01 by okandemi          #+#    #+#             */
/*   Updated: 2022/10/21 12:30:03 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_malloc_calc(char const *str, int start, int len)
{
	int		max;

	max = ft_strlen(str);
	if (max - start >= len)
		return (len);
	else
		return (max - start);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ss;
	unsigned int	total;
	unsigned int	i;

	i = 0;
	if (!s || (start > (unsigned int)ft_strlen(s)) || len > 2147483647)
		return (ft_strdup(""));
	ss = (char *)malloc(sizeof(char) * (ft_malloc_calc(s, start, len) + 1));
	if (!ss)
		return (NULL);
	total = start + len;
	while (s[start] && start < total)
	{
		ss[i] = s[start];
		i++;
		start++;
	}
	ss[i] = '\0';
	return (ss);
}
