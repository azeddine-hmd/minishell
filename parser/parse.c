#include "parser.h"

char	*parse(const char *cmdln, t_list **cmds, int prev_ret)
{
	t_list	*cmdln_lst;
	char	*syntax_err;

	(void)prev_ret;
	if (cmdln == NULL || !cmds || ft_strlen(cmdln) == 0)
		return (NO_SYNTAX_ERROR);
	cmdln_lst = get_simplified_cmdln(cmdln);
	syntax_err = check_syntax_err(cmdln_lst);
	if (syntax_err == NO_SYNTAX_ERROR)
	{
		create_cmds(cmds, cmdln_lst);
		ft_lstclear(&cmdln_lst, str_del);
		print_all_cmds(*cmds);
		return (NO_SYNTAX_ERROR);
	}
	ft_lstclear(&cmdln_lst, str_del);
	return (syntax_err);
}
