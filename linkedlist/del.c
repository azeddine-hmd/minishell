#include "linkedlist.h"

void	ft_lstdelone(t_list *lst, void (*del) (void*))
{
	del(lst->content);
	free(lst);
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
