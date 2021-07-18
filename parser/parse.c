#include "parser.h"

char	*parse(const char *cmdln, t_cmd **head, int prev_ret)
{
	t_list	*cmdln_lst;

	if (cmdln == NULL || !head || ft_strlen(cmdln) == 0)
		return (NO_SYNTAX_ERROR);
	cmdln_lst = get_simplified_cmdln(cmdln, prev_ret);
	//TODO: check syntax error
	//
	create_cmds(head, cmdln_lst);
	ft_lstclear(&cmdln_lst, str_del);
	return (NO_SYNTAX_ERROR);
}
