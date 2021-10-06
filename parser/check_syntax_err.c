#include "parser.h"

static void		format_token(const char *token, char **syntax_error)
{
	const char	*left = "syntax error near unexpected token `";
	const char	*right = "'";
	char		*tmp;

	*syntax_error = xstrjoin(left, token);
	tmp = *syntax_error;
	*syntax_error = xstrjoin(*syntax_error, right);
	xfree(tmp);
}

static t_bool	token_errs(t_list *cmdln_lst, char **syntax_error)
{
	const char *token_newline = "newline";

	if (is_token(cmdln_lst->content) && !ft_strcmp(cmdln_lst->content, PIPE))
	{
		format_token(cmdln_lst->content, syntax_error);
		return (true);
	}
	while (cmdln_lst)
	{
		if (is_token(cmdln_lst->content))
		{
			if (ft_lsthas_next(cmdln_lst) && is_token(cmdln_lst->next->content))
			{
				format_token(cmdln_lst->next->content, syntax_error);
				return (true);
			}
			if (!ft_lsthas_next(cmdln_lst) && is_token(cmdln_lst->content))
			{
				format_token(token_newline, syntax_error);
				return (true);
			}
		}
		cmdln_lst = cmdln_lst->next;
	}
	return (false);
}

char	*check_syntax_err(t_list *cmdln_lst)
{
	char	*syntax_err;

	if (token_errs(cmdln_lst, &syntax_err))
		return (syntax_err);
	return (NO_SYNTAX_ERROR);
}
