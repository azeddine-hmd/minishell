#include "parser.h"

void	create_cmds(t_list **cmds, t_list *cmdln_lst)
{
	const char	*pipe = "|";
	t_cmd		*cmd;
	t_list		*iterator;
	t_bool		is_piped;

	iterator = cmdln_lst;
	cmd = (t_cmd*)xmalloc(sizeof(t_cmd));
	is_piped = false;
	while (iterator)
	{
		while (iterator && ft_strcmp(iterator->content, pipe))
		{
			//TODO: fill commands
			cmd->is_piped = is_piped;
			if (is_token(iterator->content))
			{
				add_token_to_cmd(cmdln_lst, cmd, iterator);
				iterator = iterator->next;
			}
			ft_lstadd_back(cmds, ft_lstnew(cmd));
			iterator = iterator->next;
			is_piped = true;
		}
		if (is_null(iterator))
			break ;
		iterator = iterator->next;
	}
}
