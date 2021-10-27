#include "parser.h"

int		getret(char **env)
{
	char	*ret_str;
	int		ret;

	ret_str = pa_getenv(env, "?");
	ret = ft_atoi(ret_str);
	xfree(ret_str);
	return (ret);
}
