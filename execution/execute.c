#include "execution.h"

int	execute(t_cmd *cmds, const char *cmdln)
{
	(void)cmds;
	(void)cmdln;
	//TODO: execute commands
	system(cmdln);
	return (EXIT_SUCCESS);
}
