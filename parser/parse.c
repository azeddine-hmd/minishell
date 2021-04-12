#include "parser.h"

static t_cmd	*get_last_cmd(t_cmd *head)
{
	while (head->next != NULL)
		head = head->next;
	return (head);
}

static void	add_cmd(t_cmd **a_head, t_cmd *cmd)
{
	t_cmd	*last_cmd;

	if (*a_head == NULL)
		*a_head = cmd;
	else
	{
		last_cmd = get_last_cmd(*a_head);
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

void	parse(const char *cmdli, t_cmd **a_head, char **synerr)
{
	t_cmd	*cmd;
	size_t	i;
	size_t	start;
	t_bool	is_next_pipe;
	char	*cmd_string;

	if (cmdli == NULL || !a_head || ft_strlen(cmdli) == 0)
		return ;
	*synerr = NULL;
	*a_head = NULL;
	start = 0;
	is_next_pipe = false;
	i = -1;
	while (cmdli[++i])
	{
		if (cmdli[i] != ';' && cmdli[i] != '|')
			continue ;
		cmd_string = xsubstr(cmdli, start, i - start);
		cmd = get_cmd(cmd_string, is_next_pipe);
		add_cmd(a_head, cmd);
		if (cmdli[i] == '|')
			is_next_pipe = true;
		else
			is_next_pipe = false;
		start = i + 1;
	}
	cmd_string = xsubstr(cmdli, start, ft_strlen(cmdli));
	cmd = get_cmd(cmd_string, is_next_pipe);
	add_cmd(a_head, cmd);
}
