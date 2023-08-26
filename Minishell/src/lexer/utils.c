/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:55:51 by okandemi          #+#    #+#             */
/*   Updated: 2023/07/19 16:55:52 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	quo_count(int quo, char *input)
{
	int	i;
	int	count;
	int	diff_quo;

	i = 0;
	count = 0;
	diff_quo = 0;
	while (input[i])
	{
		if (quo == input[i] && (!diff_quo || diff_quo % 2 == 0))
			count++;
		if ((input[i] == '\'' || input[i] == '"') && input[i] != quo
			&& (!count || count % 2 == 0))
			diff_quo++;
		i++;
	}
	return (count);
}

void	reset_ver(t_lexer *t_lex)
{
	t_lex->i = 0;
	t_lex->j = 0;
	t_lex->k = 0;
	t_lex->tmp = 0;
	t_lex->count_token = 0;
	t_lex->errflag = 0;
}

int	is_great(t_lexer *t_lex)
{
	if (t_lex->input[t_lex->i] == '>')
		return (1);
	if (t_lex->input[t_lex->i] == '<')
		return (0);
	return (-1);
}

char	*ft_str_cat(char *dest, char src)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!dest)
	{
		tmp = malloc(sizeof(char) * 2);
		tmp[0] = src;
		tmp[1] = '\0';
		return (tmp);
	}
	while (dest[i])
		i++;
	tmp = malloc(sizeof(char) * i + 2);
	i = 0;
	while (dest[i])
	{
		tmp[i] = dest[i];
		i++;
	}
	tmp[i++] = src;
	tmp[i] = '\0';
	free(dest);
	return (tmp);
}

void	quot_from_quot(t_lexer *t_lex)
{
	int	tmp;

	tmp = t_lex->i;
	t_lex->tmp = t_lex->input[t_lex->i++];
	while (t_lex->input[t_lex->i])
	{
		if (t_lex->tmp == '"' && t_lex->input[t_lex->i] == '$')
			add_dolar(t_lex);
		if (t_lex->input[t_lex->i] == t_lex->tmp)
		{
			if (t_lex->i - tmp == 1)
				t_lex->token[t_lex->k] = ft_str_cat(t_lex->token[t_lex->k], 0);
			t_lex->i++;
			break ;
		}
		t_lex->token[t_lex->k] = ft_str_cat(t_lex->token[t_lex->k],
				t_lex->input[t_lex->i++]);
	}
}
