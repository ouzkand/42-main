/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:22:32 by ydegerli          #+#    #+#             */
/*   Updated: 2022/10/20 18:07:32 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (s1 && !s2)
		return ((char *)s1);
	if (!s1 && s2)
		return ((char *)s2);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	new = (char *)malloc((i + j) + 1);
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		new[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new[j++] = s2[i++];
	new[j] = '\0';
	return (new);
}
/*#include <stdio.h>
int main ()
{
	char yusuf[] = "yusuf";
	char degerli[] = "degerli";
	printf("%s", ft_strjoin(yusuf, degerli));
}*/
