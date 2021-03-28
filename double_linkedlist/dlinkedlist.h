/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlinkedlist.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 11:45:41 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/03/28 14:04:11 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLINKEDLIST_H
# define DLINKEDLIST_H

typedef struct	s_dll
{
	int				is_piped;
	int				fd;
	char			*args;
	char			*command;
	char			redirection;
	struct s_dll	*next;
	struct s_dll	*previous;
}				t_dll;

t_dll	*parse_line(const char *s);

#endif
