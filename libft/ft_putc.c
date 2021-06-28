#include "libft.h"

int		ft_putc(int c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
