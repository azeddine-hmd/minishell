#include "libft.h"

int		address_to_index(const char *s, char *address)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (&(s[i]) == address)
			return (i);
		i++;
	}
	return (INDEX_NOT_FOUND);
}
