#include "parser.h"

static t_bool	is_not_valid_input(const char *cmdln, t_cmd **head)
{
	if (cmdln == NULL || !head || ft_strlen(cmdln) == 0)
		return (true);
	return (false);
}

char	*parse(const char *cmdln, t_cmd **head)
{
	char	*syntax_error;
	t_cmd	*cmd;
	size_t	i;
	size_t	start;
	t_bool	is_pipe;
	char	*cmd_str;

	if (is_not_valid_input(cmdln, head))
		return (NULL);
	syntax_error = check_syntax_error(cmdln);
	if (is_not_null(syntax_error))
		return (syntax_error);




	// parse
	*head = NULL;
	start = 0;
	is_pipe = false;
	i = -1;
	while (cmdln[++i] && cmdln[i] == '|')
	{
		is_pipe = true;
		cmd_str = xsubstr(cmdln, start, i - start);
		cmd = get_cmd(cmd_str, is_pipe);
		add_cmd(head, cmd);
		start = i + 1;
	}
	cmd_str = xsubstr(cmdln, start, ft_strlen(cmdln));
	cmd = get_cmd(cmd_str, is_pipe);
	add_cmd(head, cmd);
	return (NULL);
}
