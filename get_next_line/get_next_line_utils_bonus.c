/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:45:14 by okandemi          #+#    #+#             */
/*   Updated: 2022/11/11 20:03:18 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	c;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	c = 0;
	if (s1)
		while (s1[++i])
			str[i] = s1[i];
	while (s2[c])
		str[i++] = s2[c++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

char	*ft_strchr(char *str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == (char) c)
		return ((char *)&str[i]);
	return (0);
}

char	*ft_get_line(char *str)
{
	int		i;
	char	*my_line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	my_line = (char *)malloc(sizeof(char) * (i + 2));
	if (!my_line)
		return (NULL);
	i = -1;
	while (str[++i] && str[i] != '\n')
		my_line[i] = str[i];
	if (str[i] == '\n')
		my_line[i++] = '\n';
	my_line[i] = '\0';
	return (my_line);
}

char	*ft_get_last(char *str, char *line)
{
	int		i;
	char	*my_line;
	int		c;

	i = ft_strlen(line);
	if (!str[ft_strlen(line)])
	{
		free(str);
		return (NULL);
	}
	my_line = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!my_line)
		return (NULL);
	c = 0;
	while (str[i])
		my_line[c++] = str[i++];
	my_line[c] = '\0';
	free(str);
	return (my_line);
}
