#include "parser.h"

char	*parse(const char *cmdln, t_cmd **head, int prev_ret)
{
	t_list	*cmdln_lst;
	char	*syntax_err;

	(void)prev_ret;
	if (cmdln == NULL || !head || ft_strlen(cmdln) == 0)
		return (NO_SYNTAX_ERROR);
	cmdln_lst = get_simplified_cmdln(cmdln);
	syntax_err = check_syntax_err(cmdln_lst);
	if (syntax_err == NO_SYNTAX_ERROR)
	{
		create_cmds(head, cmdln_lst);
		ft_lstclear(&cmdln_lst, str_del);
		return (NO_SYNTAX_ERROR);
	}
	ft_lstclear(&cmdln_lst, str_del);
	return (syntax_err);
}
