/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strip_side_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:58:45 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/12 10:58:45 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	strip_token_lst(t_list *token_lst)
{
	char	*stripped;
	t_token	*token;

	while (token_lst)
	{
		token = (t_token *)token_lst->content;
		stripped = strip_quotes(token->value);
		if (not_null(stripped))
		{
			xfree(token->value);
			token->value = stripped;
		}
		token_lst = token_lst->next;
	}
}

static void	strip_array(char **args)
{
	char	*stripped;
	int		i;

	if (!args)
		return ;
	i = -1;
	while (++i < length(args))
	{
		stripped = strip_quotes(args[i]);
		if (is_null(stripped))
			continue ;
		xfree(args[i]);
		args[i] = stripped;
	}
}

static void	strip_cmd(t_cmd *cmd)
{
	if (not_null(cmd->args))
		strip_array(cmd->args);
	if (not_null(cmd->in_token))
		strip_token_lst(cmd->in_token);
	if (not_null(cmd->out_token))
		strip_token_lst(cmd->out_token);
}

void	strip_side_quotes(t_list *cmd_lst)
{
	t_cmd	*cmd;

	while (cmd_lst)
	{
		cmd = (t_cmd *)cmd_lst->content;
		strip_cmd(cmd);
		cmd_lst = cmd_lst->next;
	}
}
