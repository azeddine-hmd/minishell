#include "libx.h"

t_list	*ft_lstnew(void *content)
{
	t_list *element;

	element = (t_list*)xmalloc(sizeof(t_list));
	element->content = content;
	element->next = NULL;
	return (element);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		new->next = *lst;
		*lst = new;
	}
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		ft_lstlast(*lst)->next = new;
	}
}
