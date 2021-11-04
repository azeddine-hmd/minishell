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

t_list	*get_tokens_range(const char *str)
{
	t_list		*tokens_range;
	t_tkindx	*token_index;
	t_range		*range;
	t_list		*quotes_range;
	int			from;
	int			to;
	int			start;

	if (!str || *str == 0)
		return (NULL);
	tokens_range = NULL;
	quotes_range = get_quotes_range(str);
	start = 0;
	while (have_token(str + start))
	{
		token_index = get_token_index(str, start);
		if (is_null(token_index))
			break ;
		from = token_index->index;
		to = from + ft_strlen(token_index->token) - 1;
		if (!inside_quotes(quotes_range, from, to, QUOTES))
		{
			range = get_range(from, to, token_to_range_type(token_index->token));
			lstpush(&tokens_range, range);
		}
		start = to + 1;
		tkindx_del(token_index);
	}
	lstclear(&quotes_range, range_del);
	return (tokens_range);
}
