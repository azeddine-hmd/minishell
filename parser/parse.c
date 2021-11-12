/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:22:17 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/12 10:22:17 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*parse(const char *cmdln, t_list **cmds, char **env)
{
	t_list	*cmdln_lst;
	char	*syntax_err;
	char	*expanded;

	expanded = expand(cmdln, env, true);
	if (is_blank(expanded))
	{
		xfree(expanded);
		return (NO_SYNTAX_ERROR);
	}
	syntax_err = check_syntax_err(cmdln);
	if (syntax_err == NO_SYNTAX_ERROR)
	{
		cmdln_lst = get_simplified_cmdln(expanded);
		create_cmds(cmds, &cmdln_lst);
		lstclear(&cmdln_lst, str_del);
		restore_expanded_tokens(*cmds);
		syntax_err = check_valid_files(cmds);
	}
	xfree(expanded);
	return (syntax_err);
}
