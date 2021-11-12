/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:19:57 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/10 20:19:57 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

static void	target_after_head(t_list *rt, t_list *target, void (*del) (void*))
{
	t_list	*current;
	t_list	*lt;

	while (rt)
	{
		if (rt->next == target)
		{
			lt = rt;
			current = rt->next;
			rt = rt->next->next;
			ft_lstdelone(current, del);
			lt->next = rt;
			return ;
		}
		rt = rt->next;
	}
}

void	lstremove(t_list **head, t_list *target, void (*del) (void*))
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
