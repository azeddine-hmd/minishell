/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 12:20:57 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/03/28 14:04:58 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
# define CMD "echo welcome"

int		main(void)
{
	t_dll	*dll;
	char	*command_line = CMD;
	dll = parse_line(command_line);
	return (0);
}
