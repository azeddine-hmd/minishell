/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:53:46 by hboudhir          #+#    #+#             */
/*   Updated: 2021/10/29 21:10:56 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	ft_builtin_pwd(void)
{
	char	buf[1024];

	if (getcwd(buf, sizeof(buf)) == NULL)
		return (-1);
	write(1, &buf, ft_strlen(buf));
	write(1, "\n", 1);
	return (0);
}

void	ft_create_file(char *file, char *type)
{
	if (!ft_strcmp(type, ">"))
		close(open(file, O_RDWR | O_CREAT | O_TRUNC, 0666));
	else if (!ft_strcmp(type, ">>"))
		close(open(file, O_RDWR | O_CREAT | O_APPEND, 0666));
}
