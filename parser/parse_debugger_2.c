#include "parser.h"

void	print_all_partial(t_list *head)
{
	t_partial	*partial;

	while (is_not_null(head))
	{
		partial = (t_partial *)head->content;
		printf("partial->cmd_str = '%s'\n", partial->cmd_str);
		printf("partial->is_piped = '%u'\n", partial->is_piped);
		head = head->next;
	}
}
