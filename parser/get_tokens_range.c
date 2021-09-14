#include "parser.h"

//TODO: determine how to detect first tokens and how the hell i shall sort them accordenly or pushing to list how? hoow?
t_list	*get_tokens_range(const char *str)
{
	t_list		*tokens_range;
	t_tkindx	*token_range;
	t_range		*range;
	t_list		*quotes_range;
	int			from;
	int			to;
	int			start;

	tokens_range = NULL;
	quotes_range = get_quotes_range(str);
	start = 0;
	while (have_token(str + start))
	{
		token_index = get_token_index(str, start);
		if (is_null(token_index))
		{
			break ;
		}

		if (token_index->index == INDEX_NOT_FOUND)
		{
			tkindx_del(token_index);
			shell_err("get_tokens_range: IllegalState");
			break ;
		}
		from = token_index->index;
		to = from + ft_strlen(token_index->token) - 1;
		if (!inside_quotes(quotes_range, from, to, QUOTES))
		{
			range = get_range(from, to, NO_RANGE_TYPE);
			ft_lstadd_back(&tokens_range, ft_lstnew(range));
		}
		start = to + 1;
		tkindx_del(token_index);
	}
	ft_lstclear(&quotes_range, range_del);
	return (tokens_range);
}
