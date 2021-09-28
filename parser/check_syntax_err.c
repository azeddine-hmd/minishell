#include "parser.h"

t_bool	tokens_errors(t_list *cmdln_lst, char **syntax_error)
{
	t_list	*iterator;

	(void)syntax_error;
	iterator = cmdln_lst;
	while (iterator)
	{
		if (is_token(iterator->content))
		{
			//TODO: token error logic
			printf("iterator->content: %s\n", (char*)iterator->content);
		}
		iterator = iterator->next;
	}
	return (false);
}

char	*check_syntax_err(t_list *cmdln_lst)
{
	char	*syntax_err;

	if (tokens_errors(cmdln_lst, &syntax_err))
		return (syntax_err);
	return (NO_SYNTAX_ERROR);
}
