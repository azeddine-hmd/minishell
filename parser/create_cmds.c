#include "parser.h"

static void	self_init(t_list **head, t_bool *is_piped, int *start, int *i)
{
	*head = NULL;
	*is_piped = false;
	*start = 0;
	*i = 0;
}

static t_list	*get_partial_cmds(const char *cmdln)
{
	t_list		*head;
	char		*cmd_str;
	t_bool		is_piped;
	int			start;
	int			i;

	self_init(&head, &is_piped, &start, &i);
	i = -1;
	while (cmdln[++i])
	{
		if (cmdln[i] != '|')
			continue ;
		if (start == 0)
			is_piped = false;
		cmd_str = ft_substr(cmdln, start, i - start);
		push_partial(&head, cmd_str, is_piped);
		is_piped = true;
		start = i + 1;
	}
	cmd_str = ft_substr(cmdln, start, ft_strlen(cmdln));
	push_partial(&head, cmd_str, is_piped);
	return (head);
}

void	create_cmds(const char *cmdln, t_cmd **head)
{
	t_list	*partial;

	(void)head;
	partial = get_partial_cmds(cmdln);
	ft_lstclear(&partial, partial_del);
}
