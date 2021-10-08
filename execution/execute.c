#include "execution.h"

int	execute(t_list *cmds)
{
	(void)cmds;
	print_all_cmds(cmds);
	return (EXIT_SUCCESS);
}
