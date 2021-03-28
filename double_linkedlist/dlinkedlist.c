/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlinkedlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 11:46:32 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/03/28 15:13:06 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlinkedlist.h"

t_dll	*parse_line(const char *cmd)
{
	t_dll	*head;
	size_t	i;
	size_t	start;

	head = (t_dll*)malloc(sizeof(t_dll));
	ft_bzero(head, sizeof(t_dll));
	if (head == NULL)
		exit(1);

	start = 0;
	i = -1;
	while (cmd[++i])
	{
		if (cmd[i] == ';')
		{
			fill_dll(ft_substr(cmd, start, i - start + 1), );
		}
		else if (s[i] == '|')
			//TODO:
	}

	return (head);
}

void	dll_clear(t_dll *head)
{
	//TODO: iterate over every node and deallocate data
}
