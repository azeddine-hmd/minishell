#include "parser.h"

t_list	*get_simplified_cmdln(const char *cmdln, int prev_ret)
{
	t_list	*cmdln_lst;
	t_list	*quotes_range;
	char	**str_arr;

	(void)prev_ret; // suppress
	quotes_range = get_quotes_range(cmdln);
	str_arr = split_except_quotes(cmdln, ' ', quotes_range);
	cmdln_lst = string_array_to_string_list(str_arr);
	print_str_lst(cmdln_lst);
	//TODO: split_tokens_to_list
	//
	return (cmdln_lst);
}
