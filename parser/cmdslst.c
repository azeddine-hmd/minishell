/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdslst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:27:35 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/05/04 17:20:53 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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

static void xfree_cmds(t_cmd *cmds)
{
	//TODO: free cmds(s_cmd struct)
	cmds++;
}

static void	xfree_cmdslst(t_cmdslst *cmdslst)
{
	//TODO: free cmdslst(s_cmdslst struct)
	xfree_cmds(cmdslst->cmds);
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

t_cmdslst	*get_cmdslst(t_cmd *cmds, char *cmds_str)
{
	t_cmdslst *cmdslst;

	cmdslst = (t_cmdslst*)xmalloc(sizeof(t_cmdslst));
	cmdslst->cmds = cmds;
	cmdslst->cmds_str = cmds_str;
	return (cmdslst);
}
