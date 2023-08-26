/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:03:45 by okandemi          #+#    #+#             */
/*   Updated: 2023/07/19 17:03:45 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_satir(char const *s, char c)
{
	int	satir;
	int	index;

	satir = 0;
	index = 0;
	while (s[index])
	{
		while (s[index] == c && s[index])
			index++;
		if (s[index])
			satir++;
		while (s[index] != c && s[index])
			index++;
	}
	return (satir);
}

char	*ft_copy(char const *s, char c)
{
	char	*str1;
	int		index;
	int		len;

	if (!(*s))
		return (NULL);
	len = 0;
	while (s[len] != c && s[len])
		len++;
	str1 = (char *)malloc(sizeof(char) * len + 1);
	if (!(str1))
		return (NULL);
	index = 0;
	while (index < len)
		str1[index++] = *s++;
	str1[index] = '\0';
	return (str1);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		satir;
	int		i;

	if (s == NULL)
		return (NULL);
	satir = ft_satir(s, c);
	str = (char **)malloc(sizeof(char *) * (satir + 1));
	if (!(str))
		return (NULL);
	i = 0;
	while (i < satir)
	{
		while (*s == c)
			s++;
		str[i] = ft_copy(s, c);
		i++;
		while (*s != c && *s)
			s++;
	}
	str[satir] = NULL;
	return (str);
}
