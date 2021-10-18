/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boodeer <boodeer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:18:42 by hboudhir          #+#    #+#             */
/*   Updated: 2021/10/18 01:04:18 by boodeer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void		ft_create_file(char *file, char *type) // check file if doesn't exit. (Manage the error too)
{
	if (!ft_strcmp(type, ">"))
		close(open(file, O_RDWR | O_CREAT | O_TRUNC, 0666));
	else if (!ft_strcmp(type, ">>"))
		close(open(file, O_RDWR | O_CREAT | O_APPEND, 0666));
}

int			file_dont_exist(char *file)
{
	write(2, "minishell: ", 11);
	write(2, file, ft_strlen(file));
	write(2,": No such file or directory\n", 28);
	return (1);
}

t_token		**check_files(int *ret, t_cmd *cmd) // red == t_token *red
{
	int		fd;

	t_token **files;
	t_list *tmp_in;
	t_list *tmp_out;
	t_token *tmp;
	files = (t_token **)ft_calloc(2, sizeof(t_token *));
	tmp_in = cmd->in_token;
	tmp_out = cmd->out_token;
	while (tmp_in)
	{
		tmp = tmp_in->content;
		fd = open(tmp->value, O_RDONLY, 0666);
		if (fd == -1)
		{
			*ret = file_dont_exist(tmp->value);
			break ;
		}
		files[1] = tmp;
		tmp_in = tmp_in->next;
	}
	while (tmp_out)
	{
		tmp = tmp_out->content;
		ft_create_file(tmp->value, tmp->type);
		if (!ft_strcmp(tmp->type, ">") || !ft_strcmp(tmp->type, ">>"))
			files[0] = tmp;
		tmp_out = tmp_out->next;
	}


	
	//while(tmp_red->value)
	//{
	//	ft_create_file(tmp_red->value, tmp_red->type);
	//	if (tmp_red->type == 'c' || tmp_red->type == 'a')
	//		files[0] = tmp_red;
	//	else if (tmp_red->type == 'r') // implement heredoc here
	//	{
	//		tmp = open(tmp_red->value, O_RDONLY, 0666);
	//		if (tmp == -1)
	//		{
	//			*ret = file_dont_exist(tmp_red->value);
	//			break ;
	//		}
	//		files[1] = tmp_red;
	//	}
	//	//else if (tmp_red->type == 'h')
	//	//{
	//	//	char *buff;
	//	//	int		fd;
			
	//	//	ft_create_file("/tmp/minishell_tmp_file", 'c');
	//	//	fd = open("/tmo/minishell_tmp_file", O_WRONLY);
	//	//	while (1)
	//	//	{
	//	//		if (ft_!ft_strcmp())
	//	//		{
	//	//			free(buff);
	//	//			break ;
	//	//		}
	//	//		buff = readline("heredoc>");
	//	//		write(fd, buff, ft_strlen(buff));
	//	//		free(buff);
	//	//	}
			
	//	//}
	//	if (tmp_red->next)
	//		tmp_red = tmp_red->next;
	//	else
	//		break ;
	//}
	return (files);
}

int			open_file(t_token *red)
{
	if (!ft_strcmp(red->type, ">"))
		return (open(red->value, O_WRONLY | O_CREAT | O_TRUNC, 0644));
	else if (!ft_strcmp(red->type, ">>"))
		return (open(red->value, O_WRONLY | O_CREAT | O_APPEND, 0644));
	return (1);
}

int		redirections(t_cmd *cmd) // equal to check_red
{
	t_token		**files;
	int			ret;
	int			fd_in;
	int			fd_out;

	files = check_files(&ret, cmd);
	if (ret == 1)
		return (1);
	if (files[0])
	{
		fd_out = open_file(files[0]);
		dup2(fd_out, 1);
		close(fd_out);
	}
	if (files[1])
	{
		fd_in = open(files[1]->value, O_RDONLY, 0666);
		dup2(fd_in, 0);
		close(fd_in);
	}
	free(files);
	return (0);
}