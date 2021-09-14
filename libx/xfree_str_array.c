#include "libx.h"

void	xfree_str_array(char **str_arr)
{
	int i;

	if (!str_arr)
		return ;
	i = -1;
	while (str_arr[++i])
		xfree(str_arr[i]);
	xfree(str_arr);
}
