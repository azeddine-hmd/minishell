#include "minishell.h"

int		main(int argc, char **argv)
{
	t_cmd	*cmd_list;

	if (argc != 2)
		exit(1);
	setbuf(stdout, NULL);
	parse(argv[1], &cmd_list);
	print_all_cmds(cmd_list);
	return (0);
}
