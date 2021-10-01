#include "libx.h"

static int	check_equality(const char *h, const char *n, int i)
{
	size_t	j;

	j = 0;
	while (n[j])
	{
		if (n[j] != h[i])
			return (0);
		i++;
		j++;
	}
	return (1);
}

char		*ft_strstr(const char *h, const char *n)
{
	size_t	i;
	int		position;
	size_t	len;

	len = ft_strlen(h);
	if (*n == '\0')
		return ((char*)h);
	if (len == 0)
		return (NULL);
	i = -1;
	position = -1;
	while (++i <= (len - ft_strlen(n)) && h[i])
		if (h[i] == n[0])
			if (check_equality(h, n, i))
			{
				position = i;
				break ;
			}
	if (position >= 0)
		return ((char*)&h[position]);
	return (NULL);
}
