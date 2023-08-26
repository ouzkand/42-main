/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup2_scale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:54:15 by okandemi          #+#    #+#             */
/*   Updated: 2023/07/19 16:54:17 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_cmnd	*end_cmnd(int is_input, t_cmnd *t_cmd, int context)
{
	t_cmnd	*res;

	res = NULL;
	while (t_cmd->next && t_cmd->next->context == context)
	{
		if (t_cmd->next->is_input == is_input)
			res = t_cmd->next;
		t_cmd = t_cmd->next;
	}
	return (res);
}

t_cmnd	*start_end_cmnd(int is_input, t_cmnd *t_cmd, int context)
{
	t_cmnd	*res;

	res = NULL;
	while (t_cmd->prev && t_cmd->prev->context == context)
	{
		if (t_cmd->prev->is_input == is_input)
			return (t_cmd->prev);
		t_cmd = t_cmd->prev;
	}
	return (res);
}

void	redirection_scale(t_cmnd *t_cmd)
{
	t_cmnd	*tmp_output;
	t_cmnd	*tmp_input;

	tmp_output = end_cmnd(0, t_cmd, t_cmd->context);
	tmp_input = end_cmnd(1, t_cmd, t_cmd->context);
	if (tmp_output)
		dup2(tmp_output->fd[1], 1);
	else if (t_cmd->prev && t_cmd->prev->is_input == 0)
	{
		tmp_output = start_end_cmnd(0, t_cmd, t_cmd->context);
		dup2(tmp_output->fd[1], 1);
	}
	if (tmp_input)
		dup2(tmp_input->fd[0], 0);
	else if (t_cmd->prev && t_cmd->prev->is_input == 1)
	{
		tmp_input = start_end_cmnd(1, t_cmd, t_cmd->context);
		dup2(tmp_input->fd[0], 0);
	}
}

void	dup2_scale(t_cmnd *t_cmd, t_pip *pipe)
{
	if (pipe->next && pipe->prev)
	{
		dup2(pipe->prev->fd[0], 0);
		dup2(pipe->fd[1], 1);
	}
	else if (pipe->next)
		dup2(pipe->fd[1], 1);
	else if (pipe->prev)
		dup2(pipe->prev->fd[0], 0);
	if ((t_cmd->prev && t_cmd->prev->context == t_cmd->context)
		|| (t_cmd->next && t_cmd->next->context == t_cmd->context))
		redirection_scale(t_cmd);
}
