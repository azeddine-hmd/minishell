/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_string_list_to_string.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:58:09 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/10 20:58:09 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

char	*join_string_list_to_string(t_list *lst)
{
	char	*joined;
	char	*tmp;

	joined = xstrdup(lst->content);
	while (lst->next)
	{
		tmp = joined;
		joined = xstrjoin(joined, lst->next->content);
		xfree(tmp);
		lst = lst->next;
	}
	return (joined);
}
