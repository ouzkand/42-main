/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmnd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:54:19 by okandemi          #+#    #+#             */
/*   Updated: 2023/07/28 17:51:23 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	execve_run2(char *file, char **paths, t_cmnd *t_cmd, t_pip *pipe)
{
	file_add(&file, paths, t_cmd);
	dup2_scale(t_cmd, pipe);
	close_all(g_data.pipe);
	if (built_in_ctl(t_cmd->expand_cmnd_lower[0]))
		ft_builtins(t_cmd->expand_cmnd_lower, t_cmd->expand_cmnd);
	else if (execve(file, t_cmd->expand_cmnd, g_data.env) == -1 && \
			!is_executor(t_cmd->expand_cmnd))
	{
		t_cmd->error_flag = 1;
		exit(127);
	}
	exit(0);
}

void	execve_run(t_cmnd *t_cmd, char **paths, t_pip *pipe)
{
	char	*file;

	if (built_in_ctl(t_cmd->expand_cmnd_lower[0]) && get_size_t_cmd(t_cmd) == 1)
	{
		ft_builtins(t_cmd->expand_cmnd_lower, t_cmd->expand_cmnd);
		return ;
	}
	file = NULL;
	t_cmd->id = fork();
	if (t_cmd->id == 0)
		execve_run2(file, paths, t_cmd, pipe);
	close_unnecessary_fd(pipe);
	g_data.input_flag = 1;
	if (file)
		free(file);
}

void	execute_run(t_cmnd *t_cmd, t_pip *pipe)
{
	char	**path;

	g_data.executor_flag = 1;
	if (is_executor(t_cmd->expand_cmnd) == 1)
		path = ft_split(g_data.path, ':');
	else
	{
		path = malloc(sizeof(char *) * 2);
		path[0] = ft_strdup("/");
		path[1] = 0;
	}
	execve_run(t_cmd, path, pipe);
	free(path[0]);
	free(path);
}

void	exec_cmnd(t_cmnd *t_cmd, t_pip *t_pipe)
{
	t_cmd = get_cmnd(t_cmd, t_cmd->context);
	while (t_pipe && t_cmd)
	{
		get_paths();
		if (!g_data.paths && !built_in_ctl(t_cmd->expand_cmnd_lower[0]))
		{
			printf("minishell: %s: No such file or directory\n",
				t_cmd->expand_cmnd[0]);
			g_data.exit_status = 127;
		}
		else if (is_executor(t_cmd->expand_cmnd))
			execute_run(t_cmd, t_pipe);
		else if (t_cmd->is_input == 2)
			execve_run(t_cmd, g_data.paths, t_pipe);
		if (t_cmd->next)
			t_cmd = get_cmnd_next(t_cmd->next, t_cmd->context + 1);
		t_pipe = t_pipe->next;
	}
}

void	exec(t_cmnd *t_cmd)
{
	int		is;

	g_data.pipe = init_pipe();
	is = input_output(g_data.t_cmnd);
	if (t_cmd && is && !g_data.heredoc_flag)
		exec_cmnd(t_cmd, g_data.pipe);
	wait_pid_all(g_data.t_cmnd);
	close_all(g_data.pipe);
	if (!is)
		g_data.exit_status = 1;
	free_pipe(g_data.pipe);
}
