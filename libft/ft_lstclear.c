/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:17:13 by okandemi          #+#    #+#             */
/*   Updated: 2022/10/13 15:17:26 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*a;
	t_list	*tmp;

	a = (*lst);
	while (a != NULL)
	{
		tmp = a -> next;
		ft_lstdelone(a, del);
		a = tmp;
	}
	(*lst) = NULL;
}
