/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:04:34 by okandemi          #+#    #+#             */
/*   Updated: 2023/07/19 17:06:18 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1len;

	if (s1 == NULL || set == NULL)
		return (0);
	while (*s1 && ft_strchr(set,*s1))
		s1++;
	s1len = ft_strlen(s1) - 1;
	while (s1len && ft_strchr(set, s1[s1len]))
		s1len--;
	return (ft_substr(s1, 0, s1len + 1));
}
