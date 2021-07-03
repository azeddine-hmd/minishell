#include "parser.h"

void	partial_del(void *content)
{
	t_partial	*partial;

	partial = (t_partial *)content;
	free(partial->cmd_str);
	free(partial);
}

t_partial	*get_partial(char *cmd_str, t_bool is_piped)
{
	t_partial	*partial;

	partial = (t_partial *)malloc(sizeof(t_partial));
	if (is_null(partial))
		return (NULL);
	partial->cmd_str = cmd_str;
	partial->is_piped = is_piped;
	return (partial);
}

void	push_partial(t_list **head, char *cmd_str, t_bool is_piped)
{
	t_partial	*partial;
	t_list		*new;

	partial = get_partial(cmd_str, is_piped);
	if (is_null(partial))
	{
		ft_lstclear(head, partial_del);
		error();
	}
	new = ft_lstnew(partial);
	if (is_null(new))
	{
		ft_lstclear(head, partial_del);
		error();
	}
	ft_lstadd_back(head, new);
}
