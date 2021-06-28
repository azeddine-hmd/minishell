#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char	*newstr;
	int		i;

	if (s && f)
	{
		if (!(newstr = (char*)malloc(ft_strlen(s) + 1)))
			return (NULL);
		i = -1;
		while (s[++i])
			newstr[i] = f(i, s[i]);
		newstr[i] = '\0';
		return (newstr);
	}
	return (NULL);
}
