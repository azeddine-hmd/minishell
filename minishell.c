/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 08:03:16 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/04/07 08:03:18 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
# define MS_BUFFER_SIZE 100

int	_putc(int c)
{
	write (1, &c, 1);
	return (0);
}

void	ms_clear_screen(char buf[], int *i)
{
	//TODO: clear screen then print login prompt
	char *value = tgetstr("cl", NULL);
	tputs(value, 1, &_putc);
	printf(COLORS_BLUE);
	printf("minishell > ");
	printf(COLORS_DEFAULT);
	ft_bzero(buf, MS_BUFFER_SIZE);
	*i = 0;
}

void	enable_raw_mode(void)
{
	struct termios raw;

	tcgetattr(STDIN_FILENO, &raw);
	raw.c_lflag &= ~(ECHO | ISIG | ICANON);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void	init_terminal_data(void)
{
	char 	*termtype;
	int		success;

	termtype = getenv("TERM");
	if (termtype == NULL)
		err(ERR_TERMTYPE);
	success = tgetent(NULL, termtype);
	if (success < 0)
		err(ERR_TERMACCESS);
	if (success == 0)
		ferr(ERR_TERMNOTDEFINED, termtype);
}

int		main(void)
{
	t_cmd	*cmd_list;
	char	*syntax_err;

	char 	c;
	char	buf[BUFFER_SIZE];
	int	i;

	setbuf(stdout, NULL);
	init_terminal_data();
	enable_raw_mode();
	printf(COLORS_BLUE);
	printf("minishell > ");
	printf(COLORS_DEFAULT);
	ft_bzero(buf, sizeof(buf));
	i = 0;
	while (read(STDIN_FILENO, &c, 1) == 1)
	{
# define KS_BS 127
		if (c == KS_BS)
		{
			if (ft_strlen(buf) == 1)
				continue ;
			char *value = tgetstr("le", NULL);
			tputs(value, 1, &_putc);
			value = tgetstr("dc", NULL);
			tputs(value, 1, &_putc);
			buf[i] = 0;
			i--;
			continue ;
		}
# define KS_CR 10
		if (c == KS_CR)
		{
			printf("%c", c);
			// handle commands in background
			if (!ft_strncmp(buf, "clear", 5))
			{
				ms_clear_screen(buf, &i);
				continue ;
			}
			parse(buf, &cmd_list, &syntax_err);
			print_all_cmds(cmd_list);
			printf(COLORS_BLUE);
			printf("minishell > ");
			printf(COLORS_DEFAULT);
			ft_bzero(buf, sizeof(buf));
			i = 0;
			continue ;
		}
		printf("%c", c);
		buf[i] = c;
		i++;

		//parse(line, &cmd_list, &syntax_err);
		//print_all_cmds(cmd_list);
		//free(line);
	}
	return (0);
}
