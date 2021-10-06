#include "parser.h"

char	*expand(char *str)
{
	char		*expanded;
	t_envindx	*env_index;
	t_envindx	*tmp_envindx;
	t_list		*quotes_range;
	t_list		*str_lst;
	t_range		*env_range;
	char		*env;

	str_lst = NULL;
	quotes_range = get_quotes_range(str);
	env_index = get_env_index(str, 0);
	if (is_null(env_index) || inside_quotes(quotes_range, env_index->range->from, env_index->range->to, "'"))
	{
		ft_lstclear(&quotes_range, range_del);
		return (xstrdup(str));
	}
	while (is_not_null(env_index))
	{
		env_range = env_index->range;
		if (inside_quotes(quotes_range, env_range->from, env_range->to, "'"))
			continue ;
		ft_lstadd_back(&str_lst, ft_lstnew(xsubstr(str, 0, env_range->from)));
		env = getenv(env_index->name);
		if (is_not_null(env))
			ft_lstadd_back(&str_lst, ft_lstnew(xstrdup(env)));
		else
			ft_lstadd_back(&str_lst, ft_lstnew(xstrdup("")));
		ft_lstadd_back(&str_lst, ft_lstnew(xsubstr(str, env_range->to + 1, ft_strlen(str) - 1 - env_range->to + 1 + 1)));
		tmp_envindx = env_index;
		env_index = get_env_index(str, env_range->to + 1);
		envindx_del(tmp_envindx);
	}
	ft_lstclear(&quotes_range, range_del);
	expanded = join_string_list_to_string(str_lst);
	ft_lstclear(&str_lst, str_del);
	return (expanded);
}