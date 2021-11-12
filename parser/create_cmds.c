/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:26:55 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/10 22:26:55 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_bool	loop_and_create(t_list **cmds, t_list **cmdln_lst, t_pcmd *pcmd)
{
	pcmd->cmd = (t_cmd *)xmalloc(sizeof(t_cmd));
	pcmd->cmd->is_piped = pcmd->is_piped;
	while (pcmd->iterator)
	{
		while (not_null(pcmd->iterator) && is_token(pcmd->iterator->content)
			&& not_equal(pcmd->iterator->content, PIPE))
			pcmd->iterator = add_token_to_cmd(
					cmdln_lst, pcmd->cmd, pcmd->iterator);
		if (is_null(pcmd->iterator) || equal(pcmd->iterator->content, PIPE))
			break ;
		lstpush(&(pcmd->args_lst), xstrdup(pcmd->iterator->content));
		pcmd->iterator = pcmd->iterator->next;
		pcmd->is_piped = true;
	}
	if (not_null(pcmd->args_lst))
	{
		pcmd->cmd->args = string_list_to_string_array(pcmd->args_lst);
		lstclear(&(pcmd->args_lst), str_del);
	}
	lstpush(cmds, pcmd->cmd);
	if (is_null(pcmd->iterator))
		return (true);
	pcmd->iterator = pcmd->iterator->next;
	return (false);
}

void	create_cmds(t_list **cmds, t_list **cmdln_lst)
{
	t_pcmd	pcmd;

	pcmd.iterator = *cmdln_lst;
	pcmd.args_lst = EMPTY_LIST;
	pcmd.is_piped = false;
	while (pcmd.iterator)
	{
		if (loop_and_create(cmds, cmdln_lst, &pcmd))
			break ;
	}
}
