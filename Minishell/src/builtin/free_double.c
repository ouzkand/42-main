/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_double.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:56:34 by okandemi          #+#    #+#             */
/*   Updated: 2023/07/19 16:56:35 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	free_double_pointer(char ***str)
{
	int	i;

	i = 0;
	if ((*str) == NULL)
		return ;
	while ((*str)[i])
		free((*str)[i++]);
	free((*str)[i]);
	free(*str);
}
