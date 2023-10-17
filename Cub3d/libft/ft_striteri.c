/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:46:38 by ydegerli          #+#    #+#             */
/*   Updated: 2022/10/20 18:06:15 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
void	changeStr(unsigned int i, char* c)
{
	c[i] = c[i] + 1;
}
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*#include <stdio.h>
int main ()
{
    char d[] = "mehaba";
    ft_striteri(d, &uppercase);
    printf("%s", d);
}*/
