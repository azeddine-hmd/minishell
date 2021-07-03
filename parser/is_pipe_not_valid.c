#include "parser.h"

static t_bool	pipe_clash(const char *cmdln, t_list *quotes_range)
{
	t_bool	first_pipe;
	int		i;

	first_pipe = false;
	i = -1;
	while (cmdln[++i])
	{
		if (cmdln[i] == ' ')
			continue ;
		if (!first_pipe && cmdln[i] == '|'
			&& !inside_quotes(quotes_range, i, i, QUOTES))
		{
			first_pipe = true;
			continue ;
		}
		if (cmdln[i] != '|')
		{
			first_pipe = false;
			continue ;
		}
		if (first_pipe && cmdln[i] == '|'
			&& !inside_quotes(quotes_range, i, i, QUOTES))
			return (true);
	}
	return (false);
}

/*
** return true if below cases valid:
** 	pipe at the beginning of string (ignore spaces)
**	pipe at the end of string
**	pipe next to another pipe or separated only by spaces
*/

t_bool	is_pipe_not_valid(const char *cmdln, t_list *quotes_range)
{
	char	*cmdln_trimmed;
	t_bool	result;

	cmdln_trimmed = ft_strtrim(cmdln, " ");
	result = false;
	if (cmdln_trimmed[0] == '|')
		result = true;
	else if (cmdln_trimmed[ft_strlen(cmdln_trimmed) - 1] == '|')
		result = true;
	else if (pipe_clash(cmdln_trimmed, quotes_range))
		result = true;
	free(cmdln_trimmed);
	return (result);
}
