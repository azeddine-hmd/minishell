/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdslst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:27:35 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/04/13 16:17:39 by ahamdaou         ###   ########.fr       */
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
		last_cmd = get_last_cmdslst(*a_head);
		last_cmd->next = cmdslst;
	}
}

void	add_cmd(t_cmd **a_head, t_cmd *cmd)
{
	t_cmd	*last_cmd;

	if (*a_head == NULL)
	{
		*a_head = cmd;
	}
	else
	{
		last_cmd = get_last_cmd(*a_head);
		last_cmd->next = cmd;
	}
}

t_cmdslst	*get_cmdslst(t_cmd *cmds, const char cmds_str)
{
	t_cmdslst *cmdslst;

	cmdslst = (t_cmdslst*)xmalloc(sizeof(t_cmdslst));
	cmdslst->cmds = cmd;
	cmdslst->cmds_str = cmds_str;
	return (cmdslst);
}
