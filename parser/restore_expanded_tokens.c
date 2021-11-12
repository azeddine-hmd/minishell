/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_expanded_tokens.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:24:02 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/12 10:24:02 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	restore_args(char **args)
{
	int	i;

	if (is_null(args))
		return ;
	i = -1;
	while (++i < length(args))
		revert_token_change_to_string(args[i]);
}

static void	restore_tokens(t_list *tokens)
{
	t_token	*token;

	if (is_null(tokens))
		return ;
	while (tokens)
	{
		token = (t_token *)tokens->content;
		revert_token_change_to_string(token->value);
		tokens = tokens->next;
	}
}

void	restore_expanded_tokens(t_list *cmds)
{
	t_cmd	*cmd;

	while (cmds)
	{
		cmd = (t_cmd *)cmds->content;
		restore_args(cmd->args);
		restore_tokens(cmd->in_token);
		restore_tokens(cmd->out_token);
		cmds = cmds->next;
	}
}
