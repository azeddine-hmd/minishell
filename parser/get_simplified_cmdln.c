#include "parser.h"

t_list	*get_simplified_cmdln(const char *cmdln, int prev_ret)
{
	t_list	*cmdln_lst;
	t_list	*quotes_range;
	char	**cmdln_arr;

	(void)prev_ret; // suppress
	quotes_range = get_quotes_range(cmdln);
	cmdln_arr = split_except_quotes(cmdln, ' ', quotes_range);
	cmdln_lst = string_array_to_string_list(cmdln_arr);
	xfree_str_array(cmdln_arr);
	//TODO: split_tokens_to_list
	//
	return (cmdln_lst);
}
