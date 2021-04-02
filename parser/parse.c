#include "parser.h"

t_cmd	*get_last_node(t_cmd *head)
{
	while (head->next == NULL)
	{
		head = head->next;
	}
	return (head);
}

void	add_node(t_cmd **head_addr, t_cmd *node)
{
	t_cmd	*last_node;

	if (*head_addr == NULL)
	{
		*head_addr = node;
	}
	else
	{
		last_node = get_last_node(*head_addr);
		last_node->next = node;
	}
}

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
	int		is_next_pipe;

	head = NULL;
	start = 0;
	is_next_pipe = 0;
	i = -1;
	while (cmd_line[++i])
	{
		if (cmd_line[i] == ';')
			add_node(&head, get_cmd_node(xsubstr(cmd_line, start, i - start + 1), FALSE));
		else if (cmd_line[i] == '|')
			add_node(&head, get_cmd_node(xsubstr(cmd_line, start, i - start + 1), TRUE));
		start = i + 1;
	}
	add_node(&head, get_cmd_node(xsubstr(cmd_line, start, ft_strlen(cmd_line)), FALSE));

	return (head);
}
