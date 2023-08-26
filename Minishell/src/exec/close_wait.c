/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_wait.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:54:11 by okandemi          #+#    #+#             */
/*   Updated: 2023/07/19 16:54:13 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	close_all(t_pip *pipe)
{
	while (pipe->next)
	{
		close(pipe->fd[0]);
		close(pipe->fd[1]);
		pipe = pipe->next;
	}
}

void	close_unnecessary_fd(t_pip *pipe)
{
	if (pipe->next && pipe->prev)
	{
		close(pipe->prev->fd[0]);
		close(pipe->fd[1]);
	}
	else if (pipe->next)
		close(pipe->fd[1]);
	else if (pipe->prev)
		close(pipe->prev->fd[0]);
}

void	wait_pid_all(t_cmnd *t_cmd)
{
	while (t_cmd)
	{
		waitpid(t_cmd->id, &(g_data.exit_status), 0);
		g_data.input_flag = 0;
		if (WIFEXITED(g_data.exit_status))
			g_data.exit_status = WEXITSTATUS(g_data.exit_status);
		if (g_data.exit_status == 127 && t_cmd->is_input == 2
			&& !g_data.executor_flag && g_data.paths)
			printf("minishell: %s: command not found\n", t_cmd->expand_cmnd[0]);
		t_cmd = t_cmd->next;
	}
	g_data.executor_flag = 0;
}
