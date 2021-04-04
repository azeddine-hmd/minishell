#include "parser.h"

char	*get_file_name(const char *s)
{
	char	*word;
	size_t	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == ' ')
			continue ;
	}

	return (word);
}

/*
** param1: <const char*> command line string
** param2: <int> order of occurrence
*/

char	*get_next_input_redirection(const char *cmd_line, int occur)
{
	char	*file_name;
	size_t	i;

	i = -1;
	while(cmd_line[++i])
	{
		if (cmd_line[i] == '<')
	}

	return (file_name);
}
