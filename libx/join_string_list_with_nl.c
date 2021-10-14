#include "libx.h"

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
		tmp = joined;
		joined = xstrjoin(joined, lst->next->content);
		xfree(tmp);
		lst = lst->next;
	}
	return (joined);
}
