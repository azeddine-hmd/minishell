#include "parser.h"

t_cmd	*get_last_cmd(t_cmd *head)
{
	while (head->next != NULL)
		head = head->next;
	return (head);
}

void	add_cmd(t_cmd **a_head, t_cmd *cmd)
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

t_cmd	*get_cmd(const char *cmd_string, t_bool is_piped)
{
	t_cmd	*cmd;
	char	**args;

	args = ft_split(cmd_string, ' ');
	cmd = (t_cmd*)xmalloc(sizeof(t_cmd));
	cmd_init(cmd, args, is_piped);

	return (cmd);
}

void	cmd_init(t_cmd *cmd, char **args, t_bool is_piped)
{
	cmd->args = args;
	cmd->is_piped = is_piped;
}
