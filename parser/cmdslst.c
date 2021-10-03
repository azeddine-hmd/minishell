#include "parser.h"

t_bool	has_previous(t_cmdslst *cmdslst)
{
	if (is_null(cmdslst->previous))
		return (false);
	else
		return (true);
}

t_cmdslst	*get_last_cmdslst(t_cmdslst *head)
{
	while (head->next != NULL)
	{
		head = head->next;
	}
	return (head);
}

void	add_cmdslst(t_cmdslst **a_head, t_cmdslst *cmdslst)
{
	t_cmdslst *last_cmdslst;

	if (*a_head == NULL)
	{
		*a_head = cmdslst;
	}
	else
	{
		last_cmdslst = get_last_cmdslst(*a_head);
		last_cmdslst->next = cmdslst;
		cmdslst->previous = last_cmdslst;
	}
}

static void	xfree_cmdslst(t_cmdslst *cmdslst)
{
	if (cmdslst->cmds)
		ft_lstclear(&(cmdslst->cmds), cmd_del);
	if (cmdslst->cmds_str)
		xfree(cmdslst->cmds_str);
	xfree(cmdslst);
}

static void xfree_after_head(t_cmdslst *node, t_cmdslst *target)
{
	t_cmdslst *tmp;
	t_cmdslst *node_left;

	while (node->next)
	{
		if (node->next == target)
		{
			node_left = node;
			tmp = node->next;
			node = node->next->next;
			xfree_cmdslst(tmp);
			node_left->next = node;
			return ;
		}
		node = node->next;
	}
}

void	delete_cmdslst(t_cmdslst **a_head, t_cmdslst *target)
{
	t_cmdslst *tmp;

	if (!(a_head) || !(*a_head) || !target)
	{
		return ;
	}
	if (*a_head == target)
	{
		tmp = *a_head;
		*a_head = (*a_head)->next;
		xfree_cmdslst(tmp);
		return ;
	}
	xfree_after_head(*a_head, target);
}
