#include "libx.h"

/*
** [Description]
** duplicate string in heap with xmalloc.
*/

char		*xstrdup(const char *s)
{
	char	*strdup;
	int		i;

	if (!s)
		return (NULL);
	strdup = (char*)xmalloc(ft_strlen(s) + 1);
	i = -1;
	while (s[++i])
		strdup[i] = s[i];
	strdup[i] = '\0';
	return (strdup);
}

/*
** [Description]
** join two strings and make a new one with xmalloc.
*/

char		*xstrjoin(const char *s1, const char *s2)
{
	char	*joined;
	int		i;
	int		j;

	if (!s1)
		return (xstrdup(s2));
	if (!s2)
		return (xstrdup(s1));
	joined = xmalloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = -1;
	while (s1[++i])
		joined[i] = s1[i];
	j = -1;
	while (s2[++j])
		joined[i++] = s2[j];
	joined[i] = '\0';
	return (joined);
}

/*
** [Description]
** join list strings with xmalloc.
*/

char		*xstrjoin_arr(const char **arglst, size_t n)
{
	char	*joined;
	char	*tmp;
	size_t	i;

	tmp = NULL;
	joined = NULL;
	i = -1;
	while (++i < n)
	{
		tmp = joined;
		joined = xstrjoin(joined, arglst[i]);
		if (tmp)
			xfree(tmp);
	}
	return (joined);
}
