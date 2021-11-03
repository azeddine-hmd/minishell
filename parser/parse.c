#include "parser.h"

char	*parse(const char *cmdln, t_list **cmds, char **env)
{
	t_list	*cmdln_lst;
	char	*syntax_err;

	if (is_blank(cmdln))
		return (NO_SYNTAX_ERROR);
	cmdln_lst = get_simplified_cmdln(cmdln, env);
	print_list_str(cmdln_lst);
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
