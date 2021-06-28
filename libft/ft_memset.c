#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*b_char;

	b_char = (unsigned char*)b;
	i = 0;
	while (i < len)
	{
		b_char[i] = c;
		i++;
	}
	return (b);
}
