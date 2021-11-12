/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:51:01 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/10 20:51:01 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_c;
	char const	*src_c;
	size_t		i;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_c = (char *)dst;
	src_c = (char const *)src;
	if (src < dst)
		while (len--)
			dst_c[len] = src_c[len];
	else if (src > dst)
	{
		i = -1;
		while (++i < len)
			dst_c[i] = src_c[i];
	}
	return (dst);
}
