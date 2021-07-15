#include "parser.h"

void	token_del(void *content)
{
	t_token	*token;

	token = (t_token*)content;
	free(token->value);
	free(token);
}

t_token	*get_token(char type, char *value)
{
	t_token	*token;

	token = (t_token *)xmalloc(sizeof(t_token));
	if (is_null(token))
		return (NULL);
	token->type = type;
	token->value = value;
	return (token);
}

void	push_token(t_list **head, char type, char *value)
{
	t_token *token;

	token = get_token(type, value);
	ft_lstadd_back(head, ft_lstnew(token));
}
