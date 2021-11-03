#include "parser.h"

char	*expand(const char *str, char **env, t_bool apply_tk_change)
{
	char		*expanded;
	t_envindx	*env_index;
	t_envindx	*tmp_envindx;
	t_list		*quotes_range;
	t_list		*str_lst;
	t_range		*env_range;
	char		*env_var;

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
		env_var = pa_getenv(env, env_index->name);
		if (apply_tk_change)
			apply_token_change_to_string(env_var);
		if (is_not_null(env))
			ft_lstadd_back(&str_lst, ft_lstnew(xstrdup(env_var)));
		else
			ft_lstadd_back(&str_lst, ft_lstnew(xstrdup("")));
		xfree(env_var);
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
