#include "parser.h"

char	**split_except_quotes(const char *s, char c, t_list *quotes_range)
{
	char	**arr;
	char	*processed;
	int		i;

	processed = xstrdup(s);
	i = -1;
	while (processed[++i])
	{
		if (processed[i] == c && !inside_quotes(quotes_range, i, i, QUOTES))
			processed[i] = CHAR_PLACEHOLDER;
	}
	arr = xsplit(processed, CHAR_PLACEHOLDER);
	xfree(processed);
	return (arr);
}
