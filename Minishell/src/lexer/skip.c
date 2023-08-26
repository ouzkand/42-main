/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:55:27 by okandemi          #+#    #+#             */
/*   Updated: 2023/07/19 16:58:11 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	skip_operator(t_lexer *t_lex)
{
	if (t_lex->input[t_lex->i] == '<' || t_lex->input[t_lex->i] == '>')
		red_cntrl(t_lex);
	if (t_lex->input[t_lex->i] == '|')
	{
		g_data.pipe_count++;
		pipe_cntrl(t_lex);
	}
}

void	skip_cmnd_arg(t_lexer *t_lex)
{
	int	is;

	is = 0;
	while (t_lex->input[t_lex->i])
	{
		if ((t_lex->input[t_lex->i] == '\''
				|| t_lex->input[t_lex->i] == '"') && !is)
			is = t_lex->input[t_lex->i];
		else if (ft_strchr(" <>|", t_lex->input[t_lex->i]) && !is)
			break ;
		else if (t_lex->input[t_lex->i] == is)
			is = 0;
		t_lex->i++;
	}
	t_lex->count_token++;
}

int	skip_space(char *input, int *i)
{
	while (input[*i] == ' ')
		(*i)++;
	if (input[*i] == '\0')
		return (0);
	return (1);
}

void	skip_quot2(t_lexer *t_lex, char quot)
{
	if ((t_lex->input[t_lex->i] == '\'' || t_lex->input[t_lex->i] == '"')
		&& t_lex->input[t_lex->i] != quot && !(t_lex->tmp % 2))
		t_lex->j++;
	if (t_lex->input[t_lex->i] == quot && (!t_lex->j || !(t_lex->j % 2)))
		t_lex->tmp++;
}

void	skip_quot(t_lexer *t_lex, char quot)
{
	if (!is_valid_quot(t_lex, t_lex->input[t_lex->i]))
		return ;
	t_lex->tmp = 1;
	while (t_lex->input[t_lex->i])
	{
		t_lex->i++;
		skip_quot2(t_lex, quot);
		if ((t_lex->input[t_lex->i] && t_lex->input[t_lex->i] == quot
				&& t_lex->input[t_lex->i + 1]
				&& t_lex->input[t_lex->i + 1] == quot))
			continue ;
		else if (ft_strchr("< >|", t_lex->input[t_lex->i])
			&& t_lex->tmp % 2 == 0)
			break ;
		else if (t_lex->input[t_lex->i + 1] && !ft_strchr("< >|",
				t_lex->input[t_lex->i + 1]))
			continue ;
		else if (t_lex->input[t_lex->i] && t_lex->input[t_lex->i] == quot
			&& t_lex->tmp % 2 == 0)
		{
			t_lex->i++;
			break ;
		}
	}
	t_lex->count_token++;
}
