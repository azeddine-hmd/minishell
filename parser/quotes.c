#include "parser.h"

t_bool	inside_quotes(t_list *range, int from, int to, const char *types)
{
	t_bool	found;
	t_range	*range_casted;

	found = false;
	while (range)
	{
		range_casted = (t_range *)range->content;
		if (ft_strchr(types, range_casted->type))
		{
			found = inside_range(range_casted, from, to, range_casted->type);
			if (found)
				return (true);
		}
		range = range->next;
	}
	return (found);
}
