/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkindx_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:49:33 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/12 11:49:33 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	tkindx_del(void *content)
{
	t_tkindx	*token_index;

	token_index = (t_tkindx *)content;
	xfree(token_index->token);
	xfree(token_index);
}
