/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:55:54 by okandemi          #+#    #+#             */
/*   Updated: 2023/07/19 16:55:56 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_token(t_token *t_tok)
{
	t_token	*t_tmp;

	while (t_tok)
	{
		t_tmp = t_tok->next;
		free(t_tok->cmnd[0]);
		free(t_tok->cmnd);
		free(t_tok);
		t_tok = t_tmp;
	}
}

void	free_pipe(t_pip	*pip)
{
	t_pip	*tmp;

	while (pip)
	{
		tmp = pip->next;
		free(pip);
		pip = tmp;
	}
}

void	free_lower_string(t_cmnd *t_cmd)
{
	int	i;

	while (t_cmd)
	{
		i = 0;
		while (t_cmd->expand_cmnd_lower[i])
		{
			free(t_cmd->expand_cmnd_lower[i]);
			i++;
		}
		if (t_cmd->expand_cmnd_lower)
			free(t_cmd->expand_cmnd_lower);
		t_cmd = t_cmd->next;
	}
}

void	exit_free(int is)
{
	t_cmnd	*t_tmp;
	int		i;

	if (is != -1)
	{
		free_lower_string(g_data.t_cmnd);
		free_token(g_data.t_token);
		while (g_data.t_cmnd)
		{
			i = 0;
			free(g_data.t_cmnd->expand_cmnd);
			t_tmp = g_data.t_cmnd->next;
			free(g_data.t_cmnd);
			g_data.t_cmnd = t_tmp;
		}
	}
	if (g_data.input && !g_data.heredoc_flag)
		free(g_data.input[0]);
	if (is == 1)
	{
		printf("exit\n");
		exit(1);
	}
}
