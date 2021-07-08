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

	token = (t_token *)malloc(sizeof(t_token));
	if (is_null(token))
		return (NULL);
	token->type = type;
	token->value = value;
	return (token);
}

void	push_token(t_list **head, char type, char *value)
{
	t_token *token;
	t_list	*new;

	token = get_token(type, value);
	if (is_null(token))
	{
		ft_lstclear(head, token_del);
		error();
	}
	new = ft_lstnew(token);
	if (is_null(new))
	{
		free(token);
		ft_lstclear(head, token_del);
		error();
	}
}
