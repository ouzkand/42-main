/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:03:56 by okandemi          #+#    #+#             */
/*   Updated: 2023/07/19 17:03:58 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	slen;

	slen = ft_strlen(s1);
	str = malloc(sizeof(char) * slen + 1);
	if (str == NULL)
		return (0);
	ft_strlcpy(str, s1, slen + 1);
	return (str);
}
