#include "libx.h"

void	alloc_fail(void)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Allocation failure\n", 2);
	lst_clear(*xmalloc_head());
	exit(1);
}
