#include "libx.h"

void	ft_lstdelone(t_list *lst, void (*del) (void*))
{
	del(lst->content);
	xfree(lst);
}

void	ft_lstclear(t_list **lst, void (*del) (void*))
{
	while (*lst)
	{
		ft_lstdelone(*lst, del);
		*lst = (*lst)->next;
	}
	*lst = NULL;
}
