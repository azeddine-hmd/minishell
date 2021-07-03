#include "parser.h"

char	*check_syntax_error(const char *cmdln, t_list *quotes_range)
{
	if (is_pipe_not_valid(cmdln, quotes_range))
		return (ERR_PIPE);
	return (NULL);
}
