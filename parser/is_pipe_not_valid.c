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
** 	pipe at the beginning of string
**	pipe at the end of string
**	pipe next to another pipe or separated only by spaces
*/

t_bool	is_pipe_not_valid(const char *cmdln, t_list *quotes_range)
{
	size_t	first_index;
	size_t	last_index;

	first_index = 0;
	last_index = ft_strlen(cmdln) - 1;
	if (cmdln[first_index] == '|')
		return (true);
	else if (cmdln[last_index] == '|')
		return (true);
	else if (pipe_clash(cmdln, quotes_range))
		return (true);
	return (false);
}
