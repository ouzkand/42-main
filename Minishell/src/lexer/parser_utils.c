/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:55:16 by okandemi          #+#    #+#             */
/*   Updated: 2023/07/19 16:55:17 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	count_cmnd(t_token *t_token)
{
	int	count;

	count = 0;
	if (t_token->if_red)
	{
		if (t_token->next)
			count += 2;
		else
			count = 1;
		return (count);
	}
	while (t_token)
	{
		if (!t_token->if_pipe && !t_token->if_red)
			count++;
		else
			break ;
		t_token = t_token->next;
	}
	return (count);
}

t_cmnd	*new_node(int count_cmnd, t_cmnd *t_prev)
{
	t_cmnd	*t_res;

	t_res = malloc(sizeof(t_cmnd));
	t_res->expand_cmnd = malloc(sizeof(char *) * (count_cmnd + 1));
	t_res->expand_cmnd_lower = malloc(sizeof(char *) * (count_cmnd + 1));
	t_res->expand_cmnd[count_cmnd] = NULL;
	t_res->expand_cmnd_lower[count_cmnd] = NULL;
	t_res->input_fd = -1;
	t_res->output_fd = -1;
	t_res->error_flag = 0;
	t_res->id = -1;
	pipe(t_res->fd);
	t_res->next = NULL;
	t_res->prev = t_prev;
	return (t_res);
}

int	is_input(char *c)
{
	if (ft_strchr(c, '>'))
		return (0);
	else if (ft_strchr(c, '<'))
		return (1);
	return (2);
}
