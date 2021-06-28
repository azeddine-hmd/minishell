#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	char		c_tmp;
	char		*dst_tmp;
	char const	*src_tmp;

	c_tmp = (unsigned char)c;
	dst_tmp = (char *)dst;
	src_tmp = (const char *)src;
	i = 0;
	while (i < n)
	{
		dst_tmp[i] = src_tmp[i];
		if (dst_tmp[i] == c_tmp)
			return (&dst_tmp[++i]);
		i++;
	}
	return (0);
}
