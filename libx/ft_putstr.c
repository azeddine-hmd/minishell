#include "libx.h"

void	ft_putstr(const char *s)
{
	int		i;

	if (!s)
		return ;
	i = -1;
	while (s[++i])
		ft_putchar_fd(s[i], 1);
}
