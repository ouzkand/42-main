/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:54:58 by okandemi          #+#    #+#             */
/*   Updated: 2023/07/28 17:26:24 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	is_valid_quot(t_lexer *t_lex, char quot)
{
	if (t_lex->input[t_lex->i + 1] == quot && t_lex->input[t_lex->i + 2]
		&& !ft_strchr(" <>|", t_lex->input[t_lex->i + 2]))
	{
		t_lex->i += 2;
		return (0);
	}
	if (t_lex->i > 0 && !ft_strchr(" <>|", t_lex->input[t_lex->i - 1]))
	{
		t_lex->i += 2;
		return (0);
	}
	return (1);
}

void	red_cntrl2(t_lexer *t_lex)
{
	t_lex->i++;
	t_lex->count_token++;
}

void	red_cntrl3(t_lexer *t_lex)
{
	if (t_lex->input[t_lex->i + 1] && \
		t_lex->input[t_lex->i] == t_lex->input[t_lex->i + 1])
		t_lex->i++;
	t_lex->tmp = t_lex->i + 1;
}

void	red_cntrl(t_lexer *t_lex)
{
	red_cntrl3(t_lex);
	if (t_lex->i != 0 && ((ft_strchr("|>", t_lex->input[t_lex->i - 1])
				&& !is_great(t_lex))
			|| (ft_strchr("|<", t_lex->input[t_lex->i - 1])
				&& is_great(t_lex))))
	{
		printf("minishell: syntax error near unexpected token '<'\n");
		t_lex->errflag = 1;
	}
	else if (is_great(t_lex) && t_lex->input[t_lex->i + 1] == '>')
	{
		printf("minishell: syntax error near unexpected token '>'\n");
		t_lex->errflag = 1;
	}
	else if (!t_lex->input[t_lex->i + 1]
		|| !skip_space(t_lex->input, &t_lex->tmp)
		|| t_lex->input[t_lex->tmp] == t_lex->input[t_lex->i]
		|| ft_strchr("<>", t_lex->input[t_lex->tmp]))
	{
		printf("minishell: syntax error near unexpected token 'newline'\n");
		g_data.exit_status = 258;
		t_lex->errflag = 1;
	}
	else
		red_cntrl2(t_lex);
}

void	pipe_cntrl(t_lexer *t_lex)
{
	t_lex->i++;
	skip_space(t_lex->input, &t_lex->i);
	if (!t_lex->i || !t_lex->input[t_lex->i] || !t_lex->count_token)
		;
	else if (!t_lex->input[t_lex->i - 2])
		;
	else if (t_lex->input[t_lex->i] == '|')
		;
	else
	{
		t_lex->count_token++;
		return ;
	}
	printf("minishell: syntax error near unexpected token '|'\n");
	t_lex->errflag = 1;
}
