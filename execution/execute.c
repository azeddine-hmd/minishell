#include "execution.h"

int	execute(t_list *cmds, char ***env)
{
	char	*ret;

	printf("start\n");
	print_all_cmds(cmds);
	printf("reached\n");
	ret = ft_itoa(main_function(cmds, env));
	*env = export_var("?", ret, *env);
	free(ret);
	return (EXIT_SUCCESS);
}
