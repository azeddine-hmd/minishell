#include "parser.h"

void	print_all_tokens(t_list *head)
{
	t_token	*token;

	while (head)
	{
		token = (t_token *)head->content;
		fprintf(pa_log, "token->type = %s\n", token->type);
		fprintf(pa_log, "token->value = %s\n", token->value);
		head = head->next;
	}
	fflush(NULL);
}

void		print_all_range(t_list *head)
{
	t_range	*range;

	while (not_null(head))
	{
		range = (t_range *)head->content;
		fprintf(pa_log, "range->from: %d\n", range->from);
		fprintf(pa_log, "range->to: %d\n", range->to);
		fprintf(pa_log, "range->type: %c\n", range->type);
		head = head->next;
	}
	fflush(NULL);
}
