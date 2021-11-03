#include "parser.h"

char	*expand_token_aware(const char *s, char **env)
{
	char	*expanded;
	int 	i;
	int		len;

	expanded = expand(s, env);
	len = ft_strlen(expanded);
	i = -1;
	while (++i < len)
	{
		if (expanded[i] == '|')
			expanded[i] = 1;
		else if (expanded[i] == '<')
			expanded[i] = 2;
		else if (expanded[i] == '>')
			expanded[i] = 3;
	}
	return (expanded);
}
