#include "parser.h"

void	create_cmds(const char *cmdln, t_cmd **head)
{
	t_cmd	*cmd;
	size_t	i;
	size_t	start;
	t_bool	is_pipe;
	char	*cmd_str;

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
}
