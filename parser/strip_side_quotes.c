#include "parser.h"

static char	*strip(const char *s)
{
	char	*stripped;
	char	*tmp;
	t_list	*quotes_lst;
	t_range	*quotes_range;

	quotes_lst = get_quotes_range(s);
	if (is_null(quotes_lst))
		return (NULL);
	quotes_range = (t_range*)quotes_lst->content;
	stripped = NULL;
	if (quotes_range->from == 0 && quotes_range->to == (int)(ft_strlen(s) - 1))
	{
		stripped = splitat(s, 0);
		tmp = stripped;
		stripped = splitat(stripped, (int)(ft_strlen(stripped) - 1));
		xfree(tmp);
	}
	return (stripped);
}

static void	strip_token_lst(t_list *token_lst)
{
	char	*stripped;
	t_token	*token;

	while (token_lst)
	{
		token = (t_token*)token_lst->content;
		stripped = strip(token->value);
		xfree(token->value);
		token->value = stripped;
		token_lst = token_lst->next;
	}
}

static void	strip_array(char **args)
{
	char	*stripped;
	int		i;

	if (!args)
		return ;
	i = -1;
	while (++i < length(args))
	{
		stripped = strip(args[i]);
		if (is_null(stripped))
			continue ;
		xfree(args[i]);
		args[i] = stripped;
	}
}

static void strip_cmd(t_cmd *cmd)
{
	if (is_not_null(cmd->args))
		strip_array(cmd->args);
	if (is_not_null(cmd->in_token))
		strip_token_lst(cmd->in_token);
	if (is_not_null(cmd->out_token))
		strip_token_lst(cmd->out_token);
}

void	strip_side_quotes(t_list *cmd_lst)
{
	t_cmd	*cmd;

	while (cmd_lst)
	{
		cmd = (t_cmd*)cmd_lst->content;
		strip_cmd(cmd);
		cmd_lst = cmd_lst->next;
	}
}
