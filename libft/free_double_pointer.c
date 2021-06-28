#include "libft.h"

void	free_double_pointer(char **ptr)
{
	int i;

	i = -1;
	while (ptr[++i])
		free(ptr[i]);
	free(ptr[i]);
	free(ptr);
}
