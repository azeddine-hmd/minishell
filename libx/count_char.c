#include "libx.h"

int		count_char(const char *s, char c)
{
	int	counter;
	int	i;

	counter = 0;
	i = -1;
	while (s[++i])
		if (s[i] == c)
			counter++;
	return (counter);
}
