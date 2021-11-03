#include "parser.h"

void	apply_token_change(char *c)
{
	if (*c == '|')
		*c = 1;
	else if (*c == '<')
		*c = 2;
	else if (*c == '>')
		*c = 3;
	else if (*c == '$')
		*c = 4;
}

void	revert_token_change(char *c)
{
	if (*c == 1)
		*c = '|';
	else if (*c == 2)
		*c = '<';
	else if (*c == 3)
		*c = '>';
	else if (*c == 4)
		*c = '$';
}
