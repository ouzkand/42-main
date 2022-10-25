/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:32:32 by okandemi          #+#    #+#             */
/*   Updated: 2022/10/16 14:17:44 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_word(char const *s, char c)
{
	size_t	word;
	size_t	i;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			word++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	size_t	start;
	size_t	end;

	if (!s)
		return (NULL);
	i = 0;
	tab = (char **)malloc(sizeof(char *) * (ft_word(s, c) + 1));
	if (!tab)
		return (NULL);
	start = 0;
	end = 0;
	while (i < ft_word(s, c))
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] != c && s[end])
			end++;
		tab[i++] = ft_substr(s, start, (end - start));
		start = end;
	}
	tab[i] = 0;
	return (tab);
}
