#include "libx.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	return (ft_strncmp(s1, s2, ft_max(ft_strlen(s1), ft_strlen(s2))));
}
