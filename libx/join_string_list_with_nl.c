#include "libx.h"
#include <stdio.h>

/*
** note: if list have string "\n" as last element it will be ignored
*/

char	*join_string_list_with_nl(t_list *lst)
{
	char	*joined;
	char	*tmp;

	joined = xstrdup(lst->content);
	while (lst->next)
	{
		tmp = joined;
		joined = xstrjoin(joined, "\n");
		xfree(tmp);
		if (is_not_null(lst->next->next) && ft_strcmp(lst->next->content, "\n"))
		{
			tmp = joined;
			joined = xstrjoin(joined, lst->next->content);
			xfree(tmp);
		}
		lst = lst->next;
	}
	return (joined);
}
