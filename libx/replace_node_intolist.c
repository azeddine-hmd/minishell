/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_node_intolist.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:51:09 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/10 19:51:09 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

static void	replace_head(t_replace *replace)
{
	t_list	*last;

	last = ft_lstlast(replace->new_lst);
	last->next = (*(replace->head))->next;
	*(replace->head) = replace->new_lst;
}

static void	replace_after_head(t_replace *replace)
{
	t_list	*iterator;
	t_list	*last;
	t_list	*left;
	t_list	*right;

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

/*
** replace single node in list A into list B
** if list A is empty operation aborts
** Note: for now this function expect list content to be string
*/

void	replace_node_intolist(t_replace *replace, void (*del) (void*))
{
	if (is_null(replace->target))
		return ;
	else if (*(replace->head) == replace->target)
		replace_head(replace);
	else
		replace_after_head(replace);
	ft_lstdelone(replace->target, del);
}
