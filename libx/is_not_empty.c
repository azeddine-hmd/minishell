#include "libx.h"

t_bool	is_not_empty(t_list *lst)
{
	if (lst != NULL)
		return (true);
	else
		return (false);
}
