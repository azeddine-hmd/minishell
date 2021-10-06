#include "parser.h"

void		envindx_del(void *content)
{
	t_envindx	*casted;

	if (is_null(content))
		printf("content is null\n");
	casted = (t_envindx*)content;
	range_del(casted->range);
	xfree(casted->name);
	xfree(casted);
}

t_envindx	*get_env_index(const char *str, int start)
{
	t_envindx	*env_index;
	t_range		*env_range;
	char		*found;
	int			i;

	env_index = (t_envindx*)xmalloc(sizeof(t_envindx));
	env_index->range = (t_range*)xmalloc(sizeof(t_range));
	env_range = env_index->range;
	env_index->name = xstrdup("");
	found = ft_strstr(str + start, "$");
	if (is_null(found))
	{
		envindx_del(env_index);
		return (NULL);
	}
	env_range->from = address_to_index(str, found);
	i = env_range->from + 1;
	while (i < (int)ft_strlen(str) && str[i] != '\'' && str[i] != '"')
		i++;
	if (i == env_range->from + 1)
	{
		envindx_del(env_index);
		return (NULL);
	}
	env_index->range->to = i - 1;
	env_index->name = xsubstr(str, env_index->range->from + 1, env_range->to - env_range->from);
	return (env_index);
}
