#include "libx.h"

t_bool	ft_lsthas_next(t_list *lst)
{
	if (lst->next != NULL)
		return (true);
	else
		return (false);
}
