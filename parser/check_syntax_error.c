#include "parser.h"

char		*check_syntax_error(const char *cmdln)
{
	if (is_pipe_not_valid(cmdln))
		return (ERR_PIPE);
	return (NULL);
}
