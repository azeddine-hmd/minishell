#include "parser.h"

void	create_cmds(t_list **cmds, t_list *cmdln_lst)
{
	t_cmd		*cmd;
	t_list		*iterator;
	t_list		*args_lst;
	t_bool		is_piped;

	iterator = cmdln_lst;
	args_lst = NULL;
	is_piped = false;
	while (iterator)
	{
		cmd = (t_cmd*)xmalloc(sizeof(t_cmd));
		cmd->is_piped = is_piped;
		while (iterator)
		{
			if (is_token(iterator->content))
				iterator = add_token_to_cmd(cmdln_lst, cmd, iterator);
			if (!ft_strcmp(iterator->content, PIPE))
				break ;
			ft_lstadd_back(&args_lst, ft_lstnew(iterator->content));
			iterator = iterator->next;
			is_piped = true;
		}
		cmd->args = string_list_to_string_array(args_lst);
		ft_lstclear(&args_lst, str_del);
		ft_lstadd_back(cmds, ft_lstnew(cmd));
		if (is_null(iterator))
			break ;
		iterator = iterator->next;
	}
}
