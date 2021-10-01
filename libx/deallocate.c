#include "libx.h"

void	deallocate(void)
{
	lst_clear(*xmalloc_head());
}
