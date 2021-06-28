#include "libft.h"

int		length(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}
