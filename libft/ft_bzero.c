#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*s_tmp;

	if (n == 0)
		return ;
	s_tmp = (char *)s;
	i = 0;
	while (i < n)
	{
		s_tmp[i] = '\0';
		i++;
	}
}
