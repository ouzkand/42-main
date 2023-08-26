/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:54:23 by okandemi          #+#    #+#             */
/*   Updated: 2023/07/19 16:54:25 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_cmnd	*get_cmnd(t_cmnd *t_cmd, int context)
{
	while (t_cmd && t_cmd->is_input != 2)
	{
		if (t_cmd->context != context)
			return (t_cmd->prev);
		t_cmd = t_cmd->next;
	}
	return (t_cmd);
}

t_cmnd	*get_cmnd_next(t_cmnd *t_cmd, int context)
{
	int	is;

	is = -1;
	while (t_cmd && t_cmd->is_input != 2)
	{
		if (t_cmd->context == context)
			is = context;
		else if (is != context && is != -1)
			return (t_cmd->prev);
		t_cmd = t_cmd->next;
	}
	return (t_cmd);
}
