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
	cmdln_lst = get_simplified_cmdln(expanded);
	xfree(expanded);
	syntax_err = check_syntax_err(cmdln_lst);
	if (syntax_err == NO_SYNTAX_ERROR)
	{
		create_cmds(cmds, &cmdln_lst);
		ft_lstclear(&cmdln_lst, str_del);
		restore_expanded_tokens(*cmds);
		syntax_err = check_valid_files(cmds);
	}
	else
		ft_lstclear(&cmdln_lst, str_del);
	return (syntax_err);
}
