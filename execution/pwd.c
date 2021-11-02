/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:53:46 by hboudhir          #+#    #+#             */
/*   Updated: 2021/11/02 18:39:29 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	ft_builtin_pwd(char **env)
{
	char	*buf;

	buf = xsubstr(find_strenv("PWD", env), 4,
			ft_strlen(find_strenv("PWD", env)));
	if (!buf)
		return (-1);
	write(1, buf, ft_strlen(buf));
	write(1, "\n", 1);
	xfree(buf);
	return (0);
}

void	ft_create_file(char *file, char *type)
{
	if (!ft_strcmp(type, ">"))
		close(open(file, O_RDWR | O_CREAT | O_TRUNC, 0666));
	else if (!ft_strcmp(type, ">>"))
		close(open(file, O_RDWR | O_CREAT | O_APPEND, 0666));
}
