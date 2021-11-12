/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_string_list_with_nl.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:58:36 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/10 20:58:36 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

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
		if (not_null(lst->next->next) && ft_strcmp(lst->next->content, "\n"))
		{
			tmp = joined;
			joined = xstrjoin(joined, lst->next->content);
			xfree(tmp);
		}
		lst = lst->next;
	}
	return (joined);
}
