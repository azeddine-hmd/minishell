#include "libx.h"

static void	target_after_head(t_list *curr, t_list *target, void (*del) (void*))
{
	t_list	*tmp;
	t_list	*left;

	while (curr->next)
	{
		if (curr->next == target)
		{
			left = curr;
			tmp = curr->next;
			curr = curr->next->next;
			ft_lstdelone(tmp, del);
			left->next = curr;
			return ;
		}
	}
}

void	ft_lstrem(t_list **head, t_list *target, void (*del) (void*))
{
	t_list	*tmp;
	t_list	*iterator;

	iterator = *head;
	if (iterator == target)
	{
		tmp = iterator;
		*head = (*head)->next;
		ft_lstdelone(tmp, del);
	}
	else
		target_after_head(iterator, target, del);
}
