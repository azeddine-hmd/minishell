#include "libx.h"

char	*splitat(const char *s, int index)
{
	char	*splited;
	char	*left;
	char	*right;

	if (index == 0)
		return (xsubstr(s, 1, ft_strlen(s) - 1));
	if (index == (int)(ft_strlen(s) - 1))
		return (xsubstr(s, 0, ft_strlen(s) - 1));
	left = xsubstr(s, 0, index + 1);
	right = xsubstr(s, index + 1, ft_strlen(s) - index + 1);
	splited = xstrjoin(left, right);
	xfree(left);
	xfree(right);
	return (splited);
}
