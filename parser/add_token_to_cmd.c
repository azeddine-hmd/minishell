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
			printf("found in_token %s equal to: %s\n", token, tokens[i]);
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
	(void)cmd;
	//TODO: implement
	// consume and delete cmdln_lst after filling necessary cmds
	// use push_token function
	token = (t_token*)xmalloc(sizeof(t_token));
	token->type = xstrdup(element->content);
	token->value = xstrdup(element->next->content);
	printf("token: %s\n", token->type);
	printf("value: %s\n", token->value);
	// decide which type of token is and push to the right head
	/*if (is_in_type_token())
	{
		push_token();
	}*/
}
