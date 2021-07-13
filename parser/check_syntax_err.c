#include "parser.h"

char	*check_syntax_err(const char *cmdln, t_list *quotes_range)
{
	char	**str_arr;
	t_list	*str_lst;

	// split with space and obtain it with list
	str_arr = split_except_quotes(cmdln, ' ', quotes_range);
	str_lst = string_array_to_string_list(str_arr);
	free_str_array(str_arr);

	//TODO

	return (NULL);
}
