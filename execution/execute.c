#include "execution.h"

int	execute(t_list *cmds, char **env)
{
	//(void)cmds;
	//(void)env;
	//print_all_cmds(cmds);
	main_function(cmds, env);
	return (EXIT_SUCCESS);
}
