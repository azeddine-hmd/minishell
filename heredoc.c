/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:45:52 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/09 21:45:52 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*get_heredoc_lst(t_list	*cmds)
{
	t_list	*heredoc_lst;
	t_cmd	*cmd;
	t_list	*in_token;
	t_token	*token;

	heredoc_lst = NULL;
	while (cmds)
	{
		cmd = (t_cmd *)cmds->content;
		in_token = cmd->in_token;
		while (in_token)
		{
			token = (t_token *)in_token->content;
			if (equal(token->type, HEREDOC_TOKEN))
				lstpush(&heredoc_lst, token);
			in_token = in_token->next;
		}
		cmds = cmds->next;
	}
	return (heredoc_lst);
}
