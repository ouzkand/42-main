/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:09:53 by ydegerli          #+#    #+#             */
/*   Updated: 2022/10/20 18:04:10 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
	{
		return ;
	}
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/* void	f(void *content)
{
	int i;
	char *str;
	str = (char *)content;
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
}
int main(void)
{
	t_list	*lst;
	t_list	*lst2;
	lst = ft_lstnew(ft_strdup("HeLLoWoRLD"));
	lst2 = ft_lstnew(ft_strdup("SeLaMDuNYa"));
	lst->next = lst2;
	printf("%s\n", lst->content);
	printf("%s\n", lst2->content);
	ft_lstiter(lst, f);
	printf("%s\n", lst->content);
	printf("%s\n", lst2->content);
} */
