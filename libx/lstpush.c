/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstpush.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:58:48 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/10 19:58:48 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

void	lstpush(t_list **lst, void *content)
{
	t_list	*element;

	element = ft_lstnew(content);
	ft_lstadd_back(lst, element);
}

void	lstpush_front(t_list **lst, void *content)
{
	t_list	*element;

	element = ft_lstnew(content);
	ft_lstadd_front(lst, element);
}
