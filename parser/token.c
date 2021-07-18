#include "parser.h"

void	token_del(void *content)
{
	t_token	*token;

	token = (t_token*)content;
	xfree(token->value);
	xfree(token);
}

void	push_token(t_list **head, char type, char *value)
{
	t_token *token;

	token = (t_token *)xmalloc(sizeof(t_token));
	token->type = type;
	token->value = value;
	ft_lstadd_back(head, ft_lstnew(token));
}
