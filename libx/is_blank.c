#include "libx.h"

t_bool	is_blank(const char *s)
{
	size_t	i;

	if (!s)
		return (false);
	i = -1;
	while (s[++i])
		if (s[i] != ' ')
			return (false);
	return (true);
}
