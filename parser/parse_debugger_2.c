#include "parser.h"

void	print_str_lst(t_list *str_lst)
{
	char	*str;
	int		i;

	i = 0;
	while (str_lst)
	{
		str = (char*)str_lst->content;
		fprintf(pa_log, "str_lst[%d]=%s\n", i, str);
		str_lst = str_lst->next;
		i++;
	}
	fprintf(pa_log, "\n");
	fflush(NULL);
}

void	print_str_arr(char **str_arr)
{
	int	arr_len;
	int	i;

	arr_len = length(str_arr);
	i = 0;
	while (i < arr_len)
	{
		fprintf(pa_log, "str_arr[%d] = %s\n", i, str_arr[i]);
		i++;
	}
	fprintf(pa_log, "\n");
	fflush(NULL);
}

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
	fprintf(pa_log, "\n");
	fflush(NULL);
}

void		print_all_range(t_list *head)
{
	t_range	*range;

	while (is_not_null(head))
	{
		range = (t_range *)head->content;
		fprintf(pa_log, "range->from: %d\n", range->from);
		fprintf(pa_log, "range->to: %d\n", range->to);
		fprintf(pa_log, "range->type: %c\n", range->type);
		head = head->next;
	}
	fprintf(pa_log, "\n");
	fflush(NULL);
}
