/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boodeer <boodeer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:35:19 by hboudhir          #+#    #+#             */
/*   Updated: 2021/10/11 21:43:14 by boodeer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int			valid_option(char *str)
{
	int		i;

	i = 0;
	if(str[i] == '-' && str[++i] == 'n')
	{
		while (str[++i] == 'n')
			continue ;
		if (str[i] == '\0')
			return (1);
		return (0);
	}
	return (0);
}


void		check_n(char **args, int *i, int *j)
{
	while (args[++(*i)])
	{
		if (valid_option(args[*i]))
			(*j)++;
		else
			break ;
	}
}
void		exec_echo(char **args, int i)
{
	int		c;

	c = 0;
	while (args[++i])
	{
		if (args[i][0] == '\0')
			continue ;
		if (c)
			write(1, " ", 1);
		write(1, args[i], ft_strlen(args[i]));
		c = 1;
	}
}

int			ft_builtin_echo(char **args)
{
	int		option;
	int		index;

	index = 0;
	option = 0;
	check_n(args, &index, &option); // modify the return value and give it to the var option
	exec_echo(args, index - 1);
	if (!option)
		write(1, "\n", 1);
	return (0);
}