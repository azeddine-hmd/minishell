/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:09:16 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/05/08 17:36:49 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <termcap.h>
# include <curses.h>
# include <termios.h>
# include <unistd.h>
# include <term.h>
# include "libft/libft.h"
# include "linkedlist/linkedlist.h"
# include "parser/parser.h"
# include "errors.h"

/*
 ** keys
 */

# define K_A 65
# define K_B 66
# define K_BS 127
# define K_ENTER 10
# define K_OSB 91
# define K_CTRL_D 4
# define K_CTRL_L 12
# define K_CTRL_I 9
# define K_CTRL_H 8
# define K_CTRL_K 11

/*
 ** others
 */

# define DEBUG TRUE
# define MS_PROMPT_COLOR COLORS_BLUE
# define MS_PROMPT "minishell > "
# define MS_BUFFER_SIZE 2048

typedef struct s_buf
{
	char	*buf;
	size_t	size;
	size_t	pos;
}				t_buf;

/*
 ** terminal capability
 */

typedef struct s_cap
{
	char	*le;
	char	*dc;
	char	*dc_r;
}				t_cap;

// debugging
FILE	*ms_log;
FILE	*ms_buflog;

// buffer
void		ms_bufinit(t_buf **a_buf);
void		ms_bufdel(t_buf *buf, t_cap *cap);
void		ms_bufadd(t_buf *buf, char out);
void		ms_bufrst(t_buf *buf);
void		ms_bufrpc(t_buf *buf, const char *s);

// termcap
void		ms_setup(t_cap **cap, t_buf **a_buf);
void		ms_prompt(void);

void		ms_chrdel(t_cap *cap);
void		ms_lndel(t_cap *cap, int count);

#endif
