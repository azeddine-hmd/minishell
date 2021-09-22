#include "parser.h"

t_bool	is_token(const char *s)
{
	char	**tokens;
	t_bool	found;
	int		i;

	found = false;
	tokens = xsplit(TOKENS, ' ');
	i = 0;
	while (i < length(tokens))
	{
		if (!ft_strcmp(s, tokens[i]))
			found = true;
		i++;
	}
	xfree_str_array(tokens);
	return (found);
}
