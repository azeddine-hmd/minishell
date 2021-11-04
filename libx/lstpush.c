#include "libx.h"

void	lstpush(t_list **lst, void *content)
{
	t_list	*element;

	element = ft_lstnew(content);
	ft_lstadd_back(lst, element);
}
