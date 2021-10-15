#include "minishell.h"

t_bool	has_previous(t_hist *history)
{
	if (is_null(history->previous))
		return (false);
	else
		return (true);
}

t_hist	*get_last_history(t_hist *history)
{
	while (history->next != NULL)
	{
		history = history->next;
	}
	return (history);
}

void	add_history(t_hist **head, t_hist *history)
{
	t_hist *last_history;

	if (*head == NULL)
	{
		*head = history;
	}
	else
	{
		last_history = get_last_history(*head);
		last_history->next = history;
		history->previous = last_history;
	}
}

static void	xfree_history(t_hist *history)
{

	xfree(history->cmdln_str);
	xfree(history->next);
	xfree(history->previous);
}

static void xfree_after_head(t_hist *node, t_hist *target)
{
	t_hist *tmp;
	t_hist *node_left;

	while (node->next)
	{
		if (node->next == target)
		{
			node_left = node;
			tmp = node->next;
			node = node->next->next;
			xfree_history(tmp);
			node_left->next = node;
			return ;
		}
		node = node->next;
	}
}

void	delete_history(t_hist **head, t_hist *target)
{
	t_hist *tmp;

	if (!(head) || !(*head) || !target)
	{
		return ;
	}
	if (*head == target)
	{
		tmp = *head;
		*head = (*head)->next;
		xfree_history(tmp);
		return ;
	}
	xfree_after_head(*head, target);
}
