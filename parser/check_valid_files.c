#include "parser.h"

static char	*check(const char *fname)
{
	return (NO_SYNTAX_ERROR);
}

char	*check_valid_files(t_list **cmds)
{
	t_list	*cmds_iterator;
	t_cmd	*cmd;
	t_list	*tk_iterator;
	t_token	*tk;
	char	*syntax_err;

	cmds_iterator = *cmds;
	while (cmds_iterator)
	{
		cmd = (t_cmd*)cmds_iterator->content;
		tk_iterator = cmd->in_token;
		while (tk_iterator)
		{
			tk = (t_token*)tk_iterator->content;
			if (!ft_strcmp(tk->type, "<"))
			{
				syntax_err = check(tk->value);
				return (syntax_err);
			}
			tk_iterator = tk_iterator->next;
		}
		cmds_iterator = cmds_iterator->next;
	}
	return (NO_SYNTAX_ERROR);
}
