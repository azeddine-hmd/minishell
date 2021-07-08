#include "parser.h"

void	print_arr(char **arr)
{
	int	arr_len;
	int	i;

	arr_len = length(arr);
	i = 0;
	while (i < arr_len)
	{
		printf("arr[%d] = %s\n", i, arr[i]);
		i++;
	}
}

void	print_all_tokens(t_list *head)
{
	t_token	*token;

	while (head)
	{
		token = (t_token *)head->content;
		printf("token->type = %c\n", token->type);
		printf("token->value = %s\n", token->value);
		head = head->next;
	}
}

void	print_all_partial(t_list *head)
{
	t_partial	*partial;

	while (is_not_null(head))
	{
		partial = (t_partial *)head->content;
		printf("partial->cmd_str = %s\n", partial->cmd_str);
		printf("partial->is_piped = %u\n", partial->is_piped);
		head = head->next;
	}
}

void		print_all_range(t_list *head)
{
	t_range	*range;

	while (is_not_null(head))
	{
		range = (t_range *)head->content;
		printf("range->from = %d\n", range->from);
		printf("range->to = %d\n", range->to);
		printf("range->type = %c\n", range->type);
		head = head->next;
	}
}
