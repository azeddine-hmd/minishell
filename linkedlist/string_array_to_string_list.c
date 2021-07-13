#include "linkedlist.h"

void	str_del(void *content)
{
	free(content);
}

/*
** 1: for allocation failure
** 0: if everything went as inteded
*/

static int	push_str(t_list **head, const char *s)
{
	t_list *new;
	char	*element;

	element = ft_strdup(s);
	if (element == NULL)
	{
		ft_lstclear(head, str_del);
		return (1);
	}
	new = ft_lstnew(element);
	if (new == NULL)
	{
		free(element);
		ft_lstclear(head, str_del);
		return (1);
	}
	ft_lstadd_back(head, new);
	return (0);
}

t_list	*string_array_to_string_list(char **arr)
{
	t_list	*lst;
	int		i;

	lst = NULL;
	i = -1;
	while (++i < length(arr))
	{
		if (push_str(&lst, arr[i]))
			return (NULL);
	}
	return (lst);
}
