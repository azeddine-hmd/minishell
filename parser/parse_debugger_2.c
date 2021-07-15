#include "parser.h"

void	print_str_lst(t_list *str_lst)
{
	char	*str;
	int		i;

	i = 0;
	while (str_lst)
	{
		str = (char*)str_lst->content;
		printf("str_lst[%d]=%s\n", i, str);
		str_lst = str_lst->next;
		i++;
	}
}

void	print_str_arr(char **str_arr)
{
	int	arr_len;
	int	i;

	arr_len = length(str_arr);
	i = 0;
	while (i < arr_len)
	{
		printf("str_arr[%d] = %s\n", i, str_arr[i]);
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
