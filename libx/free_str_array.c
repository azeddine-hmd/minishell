#include "libx.h"

void	free_str_array(char **str_arr)
{
	int i;

	i = -1;
	while (str_arr[++i])
		free(str_arr[i]);
	free(str_arr);
}
