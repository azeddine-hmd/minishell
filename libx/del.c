#include "libx.h"

void	ft_lstdelone(t_list *lst, void (*del) (void*))
{
	del(lst->content);
	xfree(lst);
}

void	ft_lstclear(t_list **lst, void (*del) (void*))
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}

void	lstclear(t_list **lst, void (*del) (void*))
{
	ft_lstclear(lst, del);
}
