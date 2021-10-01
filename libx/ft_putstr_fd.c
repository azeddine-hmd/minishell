#include "libx.h"

void	ft_putstr_fd(const char *s, int fd)
{
	int		i;

	if (!s)
		return ;
	i = -1;
	while (s[++i])
		ft_putchar_fd(s[i], fd);
}
