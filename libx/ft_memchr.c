#include "libx.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	char		c_casted;
	const char	*s_casted;

	i = 0;
	c_casted = (unsigned char)c;
	s_casted = (const char *)s;
	while (i < n)
	{
		if (s_casted[i] == c_casted)
			return ((void *)&s_casted[i]);
		i++;
	}
	return (0);
}
