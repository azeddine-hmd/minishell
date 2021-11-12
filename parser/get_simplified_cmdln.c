/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_simplified_cmdln.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 08:53:00 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/11/12 08:53:00 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_list	*get_simplified_cmdln(const char *cmdln)
{
	t_list	*cmdln_lst;
	t_list	*quotes_range;
	char	**cmdln_arr;

	quotes_range = get_quotes_range(cmdln);
	cmdln_arr = split_except_quotes(cmdln, ' ', quotes_range);
	lstclear(&quotes_range, range_del);
	cmdln_lst = string_array_to_string_list(cmdln_arr);
	xfree_str_array(cmdln_arr);
	separate_tokens(&cmdln_lst);
	return (cmdln_lst);
}
