#include "linkedlist.h"

int		ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while(lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

t_list	*ft_lstlast(t_list *lst)
{
	while(lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
