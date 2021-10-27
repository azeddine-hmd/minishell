#include "execution.h"

void	shell_exit(int ret)
{
	deallocate();
	exit(ret);
}
