#include "linkedlist.h"

char	**string_list_to_string_array(t_list *lst)
{
	char	**str_arr;
	char	*element;
	int		len;
	int		i;

	len = ft_lstsize(lst);
	str_arr = (char **)xmalloc(sizeof(char *) * (len + 1));
	str_arr[len] = NULL;
	i = 0;
	while (lst)
	{
		element = xstrdup((char *)lst->content);
		str_arr[i] = element;
		lst = lst->next;
		i++;
	}
	return (str_arr);
}
