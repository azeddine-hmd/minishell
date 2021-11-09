/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:47:37 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/09 21:47:37 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

void	ft_lstdelone(t_list *lst, void (*del) (void*))
{
	del(lst->content);
	xfree(lst);
}

void	ft_lstclear(t_list **lst, void (*del) (void*))
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}

void	lstclear(t_list **lst, void (*del) (void*))
{
	ft_lstclear(lst, del);
}
