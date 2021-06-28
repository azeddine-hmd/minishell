#include "libft.h"

int		ft_isalpha(int c)
{
	if (ft_toupper(c) != c || ft_tolower(c) != c)
		return (c);
	return (0);
}
