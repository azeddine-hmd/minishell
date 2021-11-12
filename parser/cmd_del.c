/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:26:40 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/10 22:26:40 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	cmd_del(void *content)
{
	t_cmd	*casted;

	casted = (t_cmd *)content;
	lstclear(&(casted->in_token), token_del);
	lstclear(&(casted->out_token), token_del);
	xfree_str_array(casted->args);
}
