#include "parser.h"

t_bool	is_token_type_of(char *token, char *type)
{
	char	**tokens;
	t_bool	found;
	int		i;

	found = false;
	tokens = xsplit(type, ' ');
	i = -1;
	while (++i < length(tokens))
	{
		if (!ft_strcmp(token, tokens[i]))
		{
			found = true;
			break ;
		}
	}
	xfree_str_array(tokens);
	return (found);
}

t_list	*add_token_to_cmd(t_list **cmdln_lst, t_cmd *cmd, t_list *element)
{
	t_list	*advanced_iterator;
	t_token	*token;

	advanced_iterator = element->next->next;
	token = (t_token*)xmalloc(sizeof(t_token));
	token->type = xstrdup(element->content);
	token->value = xstrdup(element->next->content);
	if (is_token_type_of(token->type, IN_TYPE_TOKEN))
		lstpush(&(cmd->in_token), token);
	else if (is_token_type_of(token->type, OUT_TYPE_TOKEN))
		lstpush(&(cmd->out_token), token);
	ft_lstrem(cmdln_lst, element->next, str_del);
	ft_lstrem(cmdln_lst, element, str_del);
	return (advanced_iterator);
}
