#include "minishell.h"

int		main(int argc, char **argv)
{
	t_cmd	*cmd_list;

	if (argc != 2)
		exit(1);
	cmd_list = parse(argv[1]);
	if (cmd_list == NULL)
		printf("cmd_list is NULL\n");
	print_all_cmd_nodes(cmd_list);

	return (0);
}
