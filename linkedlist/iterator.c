#include "linkedlist.h"

void	ft_lstiter(t_list *lst, void (*f) (void*))
{
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f) (void*), void (*del) (void*))
{
	t_list	*new_lst;
	t_list	*new_element;
	void *new_content;

	new_lst = NULL;
	new_content = NULL;
	while (lst)
	{
		new_content = (*f)(lst->content);
		if (new_content == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		new_element = ft_lstnew(new_content);
		if (new_element == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_element);
	}
	return (new_lst);
}
