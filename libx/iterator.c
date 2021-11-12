/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:11:16 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/10 20:11:16 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

void	ft_lstiter(t_list *lst, void (*f) (void*))
{
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f) (void*))
{
	t_list	*new_lst;
	t_list	*new_element;
	void	*new_content;

	new_lst = NULL;
	new_content = NULL;
	while (lst)
	{
		new_content = (*f)(lst->content);
		new_element = ft_lstnew(new_content);
		ft_lstadd_back(&new_lst, new_element);
	}
	return (new_lst);
}
