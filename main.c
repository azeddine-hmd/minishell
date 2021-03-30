#include "minishell.h"

int		main(int argc, char **argv)
{
	t_dll	*dll;

	if (argc != 2)
		exit(1);
	dll = parse(argv[1]);
	return (0);
}
