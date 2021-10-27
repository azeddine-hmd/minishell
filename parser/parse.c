#include "parser.h"

char	*parse(const char *cmdln, t_list **cmds, char **env)
{
	t_list	*cmdln_lst;
	char	*syntax_err;

	cmdln_lst = get_simplified_cmdln(cmdln);
	if (is_blank(cmdln))
	{
		ft_lstclear(&cmdln_lst, str_del);
		return (NO_SYNTAX_ERROR);
	}
	syntax_err = check_syntax_err(cmdln_lst);
	if (syntax_err == NO_SYNTAX_ERROR)
	{
		create_cmds(cmds, &cmdln_lst, env);
		ft_lstclear(&cmdln_lst, str_del);
		syntax_err = check_valid_files(cmds);
	}
	else
		ft_lstclear(&cmdln_lst, str_del);
	return (syntax_err);
}
