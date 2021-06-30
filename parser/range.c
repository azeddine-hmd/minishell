#include "parser.h"

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
