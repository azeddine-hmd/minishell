#include "execution.h"

int	execute(t_list *cmds, t_list **env)
{
	(void)cmds;
	(void)env;
	print_all_cmds(cmds);
	return (EXIT_SUCCESS);
}
