/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:54:37 by okandemi          #+#    #+#             */
/*   Updated: 2023/07/19 16:54:38 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	open_flag(t_cmnd *t_cmd)
{
	if (is_directory(t_cmd->expand_cmnd[1]))
		return (O_DIRECTORY);
	return (O_RDONLY);
}

int	input(t_cmnd *t_cmd)
{
	if (!ft_strcmp(t_cmd->expand_cmnd[0], "<") && !access(t_cmd->expand_cmnd[1],
			F_OK))
	{
		t_cmd->fd[0] = open(t_cmd->expand_cmnd_lower[1], open_flag(t_cmd));
		if (t_cmd->fd[0] == -1)
		{
			printf("minishell: %s:permission denied\n", t_cmd->expand_cmnd[1]);
			return (1);
		}
	}
	else if (!ft_strcmp(t_cmd->expand_cmnd[0], "<<"))
	{
		heredoc(t_cmd);
		if (g_data.heredoc_flag)
			return (0);
	}
	else
	{
		printf("minishell: %s: No such file or directory\n",
			t_cmd->expand_cmnd[1]);
		return (1);
	}
	return (0);
}

void	heredoc(t_cmnd *t_cmd)
{
	int	is;

	is = 1;
	while (ft_strcmp(t_cmd->expand_cmnd[1], g_data.input[0]))
	{
		g_data.heredoc_flag = 1;
		if (g_data.input[0])
			free(g_data.input[0]);
		g_data.input[0] = readline(">");
		if (!g_data.heredoc_flag || !g_data.input[0])
		{
			if (g_data.input)
				free(g_data.input[0]);
			g_data.heredoc_flag = 1;
			return ;
		}
		if (ft_strcmp(t_cmd->expand_cmnd[1], g_data.input[0]))
		{
			ft_putstr_fd(g_data.input[0], t_cmd->fd[1]);
			ft_putstr_fd("\n", t_cmd->fd[1]);
		}
	}
	g_data.heredoc_flag = 0;
	close(t_cmd->fd[1]);
}

int	output(t_cmnd *t_cmd)
{
	if (!t_cmd->expand_cmnd[1])
	{
		printf("minishell: ambiguous redirect\n");
		return (1);
	}
	if (!ft_strncmp(t_cmd->expand_cmnd[0], ">",
			ft_strlen(t_cmd->expand_cmnd[0]))
		&& !access(t_cmd->expand_cmnd[1], F_OK))
		unlink(t_cmd->expand_cmnd[1]);
	t_cmd->fd[1] = open(t_cmd->expand_cmnd[1],
			O_CREAT | O_RDWR | O_APPEND, 0777);
	if (t_cmd->fd[1] == -1)
	{
		printf("Minishell: %s: Permission denied\n", t_cmd->expand_cmnd[1]);
		return (1);
	}
	return (0);
}

int	input_output(t_cmnd *t_cmd)
{
	while (t_cmd)
	{
		if (t_cmd->is_input == 1)
		{
			if (input(t_cmd))
				return (0);
		}
		else if (t_cmd->is_input == 0 && t_cmd)
		{
			if (output(t_cmd))
				return (0);
		}
		t_cmd = t_cmd->next;
	}
	return (1);
}
