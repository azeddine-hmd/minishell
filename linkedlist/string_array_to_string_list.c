#include "linkedlist.h"

void	str_del(void *content)
{
	xfree(content);
}

t_list	*string_array_to_string_list(char **arr)
{
	t_list	*lst;
	char	*element;
	int		i;

	lst = NULL;
	i = -1;
	while (++i < length(arr))
	{
		element = xstrdup(arr[i]);
		ft_lstadd_back(&lst, ft_lstnew(element));
	}
	return (lst);
}
