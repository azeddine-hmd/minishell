#include "execution.h"

int	execute(t_list *cmds, char ***env)
{
	char	*ret;

	print_all_cmds(cmds);
	ret = ft_itoa(main_function(cmds, env));
	*env = export_var("?", ret, *env);
	free(ret);
	return (EXIT_SUCCESS);
}
