/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:38:42 by ydegerli          #+#    #+#             */
/*   Updated: 2022/12/01 16:38:36 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	j;

	j = 0;
	if (!s)
		return (NULL);
	while (s[j] != (char)c)
	{
		if (s[j] == '\0')
			return (NULL);
		j++;
	}
	return (&((char *)s)[j]);
}

char	*add(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		s1[0] = '\0';
	}
	if (!s2)
		return (s1);
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*line(char *str)
{
	char	*r;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	r = (char *)malloc(i + 2);
	if (!r)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		r[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		r[i] = str[i];
		i++;
	}
	r[i] = '\0';
	return (r);
}

char	*next(char *s)
{
	char	*new;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	new = (char *)malloc((ft_strlen(s) - i) + 1);
	if (!new)
		return (NULL);
	i++;
	j = 0;
	while (s[i])
		new[j++] = s[i++];
	new[j] = '\0';
	free(s);
	return (new);
}
