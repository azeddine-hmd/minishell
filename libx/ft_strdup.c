#include "libx.h"

char	*ft_strdup(const char *s1)
{
	char	*memory;
	int		i;

	if (!s1)
		return (NULL);
	memory = (char*)ft_calloc(1, ft_strlen(s1) + 1);
	if (!memory)
		return (NULL);
	i = -1;
	while (s1[++i])
		memory[i] = s1[i];
	return (memory);
}
