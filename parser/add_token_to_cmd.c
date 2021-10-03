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

void	add_token_to_cmd(t_list *cmdln_lst, t_cmd *cmd, t_list *element)
{
	t_token	*token;

	(void)cmdln_lst;
	token = (t_token*)xmalloc(sizeof(t_token));
	token->type = xstrdup(element->content);
	token->value = xstrdup(element->next->content);
	if (is_token_type_of(token->type, IN_TYPE_TOKEN))
		ft_lstadd_back(&(cmd->in_token), ft_lstnew(token));
	else if (is_token_type_of(token->type, OUT_TYPE_TOKEN))
		ft_lstadd_back(&(cmd->out_token), ft_lstnew(token));
	//TODO: consume and delete cmdln_lst after filling necessary cmds
	// call ft_lstrem() on both element and element->next
}
