#include "libx.h"

/*
** replace single node in list A into list B
** if list A is empty operation aborts
** Note: for now this function expect list content to be string
*/

void	replace_node_intolist(t_replace *replace, void (*del) (void*))
{
	t_list	*left;
	t_list	*right;
	t_list	*iterator;
	t_list	*last;

	if (is_null(replace->target))
		return ;
	else if (*(replace->head) == replace->target)
	{
		last = ft_lstlast(replace->new_lst);
		last->next = (*(replace->head))->next;
		*(replace->head) = replace->new_lst;
	}
	else
	{
		iterator = *(replace->head);
		while (iterator)
		{
			if (iterator->next == replace->target)
			{
				left = iterator;
				right = iterator->next->next;
			}
			iterator = iterator->next;
		}
		left->next = replace->new_lst;
		last = ft_lstlast(replace->new_lst);
		last->next = right;
	}
	ft_lstdelone(replace->target, del);
}
