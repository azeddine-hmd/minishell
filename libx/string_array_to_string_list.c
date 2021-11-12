/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_array_to_string_list.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:50:38 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/10 19:50:38 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

void	str_del(void *content)
{
	xfree(content);
}

t_list	*string_array_to_string_list(char **arr)
{
	t_list	*lst;
	char	*content;
	int		i;

	lst = NULL;
	i = -1;
	while (++i < length(arr))
	{
		content = xstrdup(arr[i]);
		lstpush(&lst, content);
	}
	return (lst);
}
