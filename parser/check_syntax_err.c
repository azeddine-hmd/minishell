/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_err.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:25:22 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/10 22:25:22 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	format_token(const char *token, char **syntax_error)
{
	const char	*left = "syntax error near unexpected token `";
	const char	*right = "'";
	char		*tmp;

	*syntax_error = xstrjoin(left, token);
	tmp = *syntax_error;
	*syntax_error = xstrjoin(*syntax_error, right);
	xfree(tmp);
}

static t_bool	tokens_clash_nopipe(t_list *cmdln_lst, char **syntax_error)
{
	if (is_token(cmdln_lst->content))
	{
		if (lsthas_next(cmdln_lst)
			&& not_equal(cmdln_lst->content, PIPE)
			&& is_token(cmdln_lst->next->content))
		{
			format_token(cmdln_lst->next->content, syntax_error);
			return (true);
		}
		if (!lsthas_next(cmdln_lst)
			&& not_equal(cmdln_lst->content, PIPE)
			&& is_token(cmdln_lst->content))
		{
			format_token(NEWLINE, syntax_error);
			return (true);
		}
	}
	return (false);
}

static t_bool	pipe_clash(t_list *cmdln_lst, char **syntax_error)
{
	if (is_token(cmdln_lst->content))
	{
		if (lsthas_next(cmdln_lst)
			&& is_token(cmdln_lst->next->content)
			&& equal(cmdln_lst->next->content, PIPE))
		{
			format_token(cmdln_lst->next->content, syntax_error);
			return (true);
		}
		if (!lsthas_next(cmdln_lst)
			&& is_token(cmdln_lst->content))
		{
			format_token(NEWLINE, syntax_error);
			return (true);
		}
	}
	return (false);
}

static t_bool	token_errs(t_list *cmdln_lst, char **syntax_error)
{
	if (is_token(cmdln_lst->content) && equal(cmdln_lst->content, PIPE))
	{
		format_token(cmdln_lst->content, syntax_error);
		return (true);
	}
	while (cmdln_lst)
	{
		if (tokens_clash_nopipe(cmdln_lst, syntax_error))
			return (true);
		if (pipe_clash(cmdln_lst, syntax_error))
			return (true);
		cmdln_lst = cmdln_lst->next;
	}
	return (false);
}

char	*check_syntax_err(const char *cmdln)
{
	t_list	*cmdln_lst;
	char	*syntax_err;

	cmdln_lst = get_simplified_cmdln(cmdln);
	if (token_errs(cmdln_lst, &syntax_err))
		return (syntax_err);
	lstclear(&cmdln_lst, str_del);
	return (NO_SYNTAX_ERROR);
}
