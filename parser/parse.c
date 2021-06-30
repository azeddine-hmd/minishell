#include "parser.h"

char	*parse(const char *cmdln, t_cmd **head)
{
	char	*syntax_error;
	t_list	*quotes_range;

	if (cmdln == NULL || !head || ft_strlen(cmdln) == 0)
		return (NO_SYNTAX_ERROR);
	quotes_range = get_quotes_range(cmdln);
	syntax_error = check_syntax_error(cmdln, quotes_range);
	if (is_not_null(syntax_error))
		return (syntax_error);
	else
		create_cmds(cmdln, head);
	return (NO_SYNTAX_ERROR);
}
