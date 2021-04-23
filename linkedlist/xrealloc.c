/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xrealloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 07:37:21 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/04/23 15:55:00 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

/*
** please don't be confused with stadard library realloc
** this function is totally different in implementation and behaviour
*/

void	 *xrealloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*ptr_new;

	if (new_size == 0)
	{
		xfree(ptr);
		return (NULL);
	}
	if (!ptr)
	{
		return xmalloc(new_size);
	}
	else if (new_size <= old_size)
	{
		return (ptr);
	}
	else
	{
		if (!(ptr && new_size > old_size))
			error();
		ptr_new = xmalloc(new_size);
		if (ptr_new)
		{
			ft_memcpy(ptr_new, ptr, old_size);
			xfree(ptr);
		}
		return (ptr_new);
	}
}
