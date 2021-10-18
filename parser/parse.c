#include "parser.h"

char	*parse(const char *cmdln, t_list **cmds, char **env, int prev_ret)
{
	t_list	*cmdln_lst;
	char	*syntax_err;

	(void)prev_ret;
	cmdln_lst = get_simplified_cmdln(cmdln);
	syntax_err = check_syntax_err(cmdln_lst);
	if (syntax_err == NO_SYNTAX_ERROR)
	{
		create_cmds(cmds, cmdln_lst, env);
		ft_lstclear(&cmdln_lst, str_del);
		return (NO_SYNTAX_ERROR);
	}
	ft_lstclear(&cmdln_lst, str_del);
	return (syntax_err);
}
