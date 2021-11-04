#include "parser.h"

t_tkindx	*get_token_index(const char *str, int start)
{
	t_tkindx	*token_index;
	char		*address;
	char		**tokens;
	int			i;

	if (!str || *str == 0)
		return (NULL);
	token_index = (t_tkindx *)xmalloc(sizeof(t_tkindx));
	token_index->index = INDEX_NOT_FOUND;
	tokens = xsplit(TOKENS, ' ');
	i = -1;
	while (++i < length(tokens))
	{
		address = ft_strstr(str + start, tokens[i]);
		if (is_not_null(address))
		{
			token_index->index = address_to_index(str, address);
			token_index->token = xstrdup(tokens[i]);
			return (token_index);
		}
	}
	xfree_str_array(tokens);
	xfree(token_index);
	return (NULL);
}

t_bool	have_token(const char *str)
{
	char	*sub_token;
	char	**tokens;
	int		tokens_len;
	int		i;

	if (!str || !(*str))
		return (false);
	tokens = xsplit(TOKENS, ' ');
	tokens_len = length(tokens);
	i = 0;
	while (i < tokens_len)
	{
		sub_token = ft_strstr(str, tokens[i]);
		if (is_not_null(sub_token))
		{
			xfree_str_array(tokens);
			return (true);
		}
		i++;
	}
	xfree_str_array(tokens);
	return (false);
}

void	token_del(void *content)
{
	t_token	*token;

	token = (t_token *)content;
	xfree(token->value);
	xfree(token);
}

void	push_token(t_list **head, char *type, char *value)
{
	t_token	*token;

	token = (t_token *)xmalloc(sizeof(t_token));
	token->type = type;
	token->value = value;
	lstpush(head, token);
}
