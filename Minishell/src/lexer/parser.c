/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:55:22 by okandemi          #+#    #+#             */
/*   Updated: 2023/07/19 16:55:24 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token	*split_pipe2(t_token *t_token, t_cmnd *t_tmp, int i)
{
	while (t_token && !t_token->if_pipe && !t_token->if_red)
	{
		t_tmp->expand_cmnd[i] = t_token->cmnd[0];
		t_tmp->expand_cmnd_lower[i++] = ft_strdup(t_token->cmnd[0]);
		t_token = t_token->next;
		if (t_tmp->is_input != 2)
			break ;
	}
	return (t_token);
}

t_token	*split_pipe3(t_token *t_token, t_cmnd **t_tmp, int *context, int *i)
{
	if (t_token->if_pipe)
	{
		(*context)++;
		t_token = t_token->next;
	}
	if (!t_token->if_pipe && !t_token->if_red)
	{
		(*t_tmp) = new_node(count_cmnd(t_token), *t_tmp);
		(*t_tmp)->is_input = 2;
		(*t_tmp)->context = (*context);
	}
	else if (t_token->if_red)
	{
		(*t_tmp) = new_node(count_cmnd(t_token), *t_tmp);
		(*t_tmp)->expand_cmnd[*i] = t_token->cmnd[0];
		(*t_tmp)->expand_cmnd_lower[(*i)++] = ft_strdup(t_token->cmnd[0]);
		(*t_tmp)->is_input = is_input(t_token->cmnd[0]);
		(*t_tmp)->context = (*context);
		t_token = t_token->next;
	}
	return (t_token);
}

void	split_pipe(t_token *t_token, t_cmnd **t_cmd)
{
	t_cmnd	*t_tmp;
	int		context;
	int		i;

	context = 0;
	t_tmp = NULL;
	while (t_token)
	{
		i = 0;
		t_token = split_pipe3(t_token, &t_tmp, &context, &i);
		t_token = split_pipe2(t_token, t_tmp, i);
		ft_lstadd_back_t_cmnd(t_cmd, t_tmp);
	}
}

void	parser(void)
{
	g_data.pipe_count = 0;
	g_data.t_token = lexer();
	if (!g_data.t_token)
	{
		g_data.t_cmnd = NULL;
		return ;
	}
	split_pipe(g_data.t_token, &(g_data.t_cmnd));
	upper_to_lower(g_data.t_cmnd);
}
