#include "parser.h"

void	cmd_node_init(t_cmd *cmd_node, char **args, int is_piped)
{
	cmd_node->command = args[0];
	cmd_node->args = args + 1;
	cmd_node->is_piped = is_piped;
}

t_cmd	*get_cmd_node(const char *cmd, int is_piped)
{
	t_cmd	*cmd_node;
	char	**args;

	args = ft_split(cmd, ' ');
	cmd_node = (t_cmd*)xmalloc(sizeof(t_cmd));
	cmd_node_init(cmd_node, args, is_piped);

	return (cmd_node);
}

t_cmd	*parse(const char *cmd_line)
{
	t_cmd	*head;
	size_t	i;
	size_t	start;

	// head is null for now
	head = NULL;

	start = 0;
	i = -1;
	while (cmd_line[++i])
	{
		if (cmd_line[i] == ';')
			get_cmd_node(xsubstr(cmd_line, start, i - start + 1), FALSE);
		else if (cmd_line[i] == '|')
			get_cmd_node(xsubstr(cmd_line, start, i - start + 1), TRUE);
		start = i + 1;
	}

	return (head);
}
