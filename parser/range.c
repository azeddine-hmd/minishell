#include "parser.h"

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
	free(content);
}

t_range	*get_range(int from, int to, char type)
{
	t_range	*range;

	range = (t_range *)malloc(sizeof(t_range));
	if (!range)
		return (NULL);
	range->from = from;
	range->to = to;
	range->type = type;
	return (range);
}
