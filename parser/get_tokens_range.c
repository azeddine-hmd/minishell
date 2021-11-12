/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens_range.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 08:53:34 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/12 08:53:34 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	token_to_range_type(const char *token)
{
	if (equal(token, "<<"))
		return ('1');
	else if (equal(token, ">>"))
		return ('2');
	else if (equal(token, ">"))
		return ('3');
	else if (equal(token, "<"))
		return ('4');
	else if (equal(token, "|"))
		return ('5');
	return (0);
}

char	*token_from_range_type(char range_type)
{
	char	*range_type_str;
	char	*token;

	token = NULL;
	range_type_str = xstrdup("x");
	range_type_str[0] = range_type;
	if (equal(range_type_str, "1"))
		token = "<<";
	else if (equal(range_type_str, "2"))
		token = ">>";
	else if (equal(range_type_str, "3"))
		token = ">";
	else if (equal(range_type_str, "4"))
		token = "<";
	else if (equal(range_type_str, "5"))
		token = "|";
	xfree(range_type_str);
	return (token);
}

static t_range	*get_next_range(const char *str, int start)
{
	t_tkindx	*token_index;
	t_range		*range;
	int			from;
	int			to;

	range = NULL;
	token_index = get_token_index(str, start);
	if (is_null(token_index))
		return (NULL);
	from = token_index->index;
	to = from + ft_strlen(token_index->token) - 1;
	range = get_range(from, to, token_to_range_type(token_index->token));
	tkindx_del(token_index);
	return (range);
}

t_list	*get_tokens_range(const char *str)
{
	t_list		*tokens_range;
	t_range		*range;
	t_list		*qts_rg;
	int			start;

	if (!str || *str == 0)
		return (NULL);
	tokens_range = EMPTY_LIST;
	qts_rg = get_quotes_range(str);
	start = 0;
	while (have_token(str + start))
	{
		range = get_next_range(str, start);
		if (!inside_qts(qts_rg, range, QUOTES))
			lstpush(&tokens_range, range);
		start = range->to + 1;
	}
	lstclear(&qts_rg, range_del);
	return (tokens_range);
}
