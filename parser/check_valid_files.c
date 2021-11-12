/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_files.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:26:00 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/10 22:26:00 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*format_file_error(const char *fname, const char *err)
{
	char	*joined;
	char	*tmp;

	joined = xstrdup(fname);
	tmp = joined;
	joined = xstrjoin(joined, ": ");
	xfree(tmp);
	tmp = joined;
	joined = xstrjoin(joined, err);
	xfree(tmp);
	return (joined);
}

static char	*check(const char *fname)
{
	char	*syntax_err;
	int		fd;

	syntax_err = NO_SYNTAX_ERROR;
	fd = open(fname, O_RDONLY);
	if (fd == -1)
	{
		syntax_err = format_file_error(fname, strerror(errno));
	}
	close(fd);
	return (syntax_err);
}

char	*check_valid_files(t_list **cmds)
{
	t_list	*cmds_iterator;
	t_cmd	*cmd;
	t_list	*tk_iterator;
	t_token	*tk;
	char	*syntax_err;

	cmds_iterator = *cmds;
	while (cmds_iterator)
	{
		cmd = (t_cmd *)cmds_iterator->content;
		tk_iterator = cmd->in_token;
		while (tk_iterator)
		{
			tk = (t_token *)tk_iterator->content;
			if (equal(tk->type, "<"))
			{
				syntax_err = check(tk->value);
				return (syntax_err);
			}
			tk_iterator = tk_iterator->next;
		}
		cmds_iterator = cmds_iterator->next;
	}
	return (NO_SYNTAX_ERROR);
}
