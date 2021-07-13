#include "parser.h"

char	*parse(const char *cmdln, t_cmd **head, int prev_ret)
{
	char	*syntax_error;
	t_list	*quotes_range;

	// supress unused variables
	(void)prev_ret;
	if (cmdln == NULL || !head || ft_strlen(cmdln) == 0)
		return (NO_SYNTAX_ERROR);
	quotes_range = get_quotes_range(cmdln);
	syntax_error = check_syntax_err(cmdln, quotes_range);
	ft_lstclear(&quotes_range, range_del);
	if (is_not_null(syntax_error))
		return (syntax_error);
	else
	{
		create_cmds(cmdln, head);

		// debugging
		//system(cmdln);
	}
	return (NO_SYNTAX_ERROR);
}
