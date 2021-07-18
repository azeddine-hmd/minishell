#include "parser.h"

int		get_range_len(t_range *range)
{
	return (range->to - range->from + 1);
}

t_bool	inside_range(t_range *range, int from, int to, char type)
{
	if (type != range->type)
		return (false);
	if (from > to || to < from)
		return (false);
	if (from >= range->from && to <= range->to)
		return (true);
	return (false);
}

void	range_del(void *content)
{
	xfree(content);
}

t_range	*get_range(int from, int to, char type)
{
	t_range	*range;

	range = (t_range *)xmalloc(sizeof(t_range));
	range->from = from;
	range->to = to;
	range->type = type;
	return (range);
}
