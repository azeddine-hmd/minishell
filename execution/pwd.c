/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:53:46 by hboudhir          #+#    #+#             */
/*   Updated: 2021/11/08 18:31:16 by hboudhir         ###   ########.fr       */
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

void	check_dir(char *p)
{
	DIR	*tmp;

	tmp = opendir(p);
	if (!tmp)
		return ;
	else if (tmp)
	{
		closedir(tmp);
		ft_putstr("minishell: ");
		ft_putstr(p);
		ft_putstr(": is a directory\n");
		shell_exit(126);
	}
}

int	open_failed(char *cmd)
{
	if (errno == 13 || errno == 21)
	{
		ft_putstr("minishell: ");
		ft_putstr(cmd);
		perror(": ");
		return (126);
	}
	return (-1);
}

void	ft_create_file(char *file, char *type)
{
	if (!ft_strcmp(type, ">"))
		close(open(file, O_RDWR | O_CREAT | O_TRUNC, 0666));
	else if (!ft_strcmp(type, ">>"))
		close(open(file, O_RDWR | O_CREAT | O_APPEND, 0666));
}
