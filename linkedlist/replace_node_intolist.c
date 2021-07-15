#include "linkedlist.h"

/*
** replace single node in list A into list B
** if list A is empty operation aborts
*/

void	replace_node_intolist(t_list **head, t_list *this, t_list *new_lst)
{
	t_list	*left;
	t_list	*right;
	t_list	iterator;
	t_list	*last;

	if (is_null(this))
		return ;
	else if (*head == this)
	{
		last = ft_lstlast(*head);
		last->next = *head;
		*head = new_lst;
	}
	else
	{
		iterator = *head;
		while (iterator)
		{
			if (iterator->next == this)
			{
				left = iterator;
				right = iterator->next->next;
			}
			iterator = iterator->next;
		}
		left->next = new_lst;
		last = ft_lstlast(new_lst);
		last->next = right;
	}
}
