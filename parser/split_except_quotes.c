#include "parser.h"

char	**split_except_quotes(const char *s, char c, t_list *quotes_range)
{
	char	**arr;
	char	*processed;
	int		i;

	processed = ft_strdup(s);
	i = -1;
	while (processed[++i])
	{
		if (processed[i] == c && !inside_quotes(quotes_range, i, i, QUOTES))
			processed[i] = CHAR_PLACEHOLDER;
	}
	arr = ft_split(processed, CHAR_PLACEHOLDER);
	free(processed);
	return (arr);

}
