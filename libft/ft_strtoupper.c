#include "libft.h"

char		*ft_strtoupper(char *s)
{
	int	i;

	if (!s)
		return (NULL);
	i = -1;
	while (s[++i])
		if (ft_isalpha(s[i]))
			s[i] = ft_toupper(s[i]);
	return (s);
}
