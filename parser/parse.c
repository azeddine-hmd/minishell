#include "parser.h"

static t_cmd	*get_last_cmd(t_cmd *head)
{
	while (head->next == NULL)
	{
		head = head->next;
	}
	return (head);
}

static void	add_cmd(t_cmd **head_addr, t_cmd *cmd)
{
	t_cmd	*last_cmd;

	if (*head_addr == NULL)
		*head_addr = cmd;
	else
	{
		last_cmd = get_last_cmd(*head_addr);
		last_cmd->next = cmd;
	}
}

static void	cmd_init(t_cmd *cmd, char **args, int is_piped)
{
	cmd->command = args[0];
	cmd->args = args + 1;
	cmd->is_piped = is_piped;
}

static t_cmd	*get_cmd(const char *cmd_string, int is_piped)
{
	t_cmd	*cmd;
	char	**args;

	args = ft_split(cmd_string, ' ');
	cmd = (t_cmd*)xmalloc(sizeof(t_cmd));
	cmd_init(cmd, args, is_piped);

	return (cmd);
}

void	parse(const char *cmd_line, t_cmd **head_addr)
{
	t_cmd	*cmd;
	size_t	i;
	size_t	start;
	int		is_next_pipe;
	char	*cmd_string;

	*head_addr = NULL;
	start = 0;
	is_next_pipe = FALSE;
	i = -1;
	reformat_variables()
	while (cmd_line[++i])
	{
		if (cmd_line[i] != ';' || cmd_line[i] != '|')
			continue ;
		cmd_string = xsubstr(cmd_line, start, i - start + 1);
		cmd = get_cmd(cmd_string, is_next_pipe);
		add_cmd(head_addr, cmd);
		is_next_pipe = (cmd_line[i] == '|') ? TRUE : FALSE;
		start = i + 1;
	}
	cmd_string = xsubstr(cmd_line, start, ft_strlen(cmd_line));
	cmd = get_cmd(cmd_string, is_next_pipe);
	add_cmd(head_addr, cmd);
}
