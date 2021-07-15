NAME = libparser.a

CFLAGS = -Wall -Wextra -Werror \
		 -g \

CC = gcc

SRC = parse.c \
	  cmds.c \
	  cmdslst.c \
	  parse_debugger.c \
	  parse_debugger_2.c \
	  check_syntax_err.c \
	  is_pipe_not_valid.c \
	  create_cmds.c \
	  get_quotes_range.c \
	  range.c \
	  quotes.c \
	  token.c \
	  split_except_quotes.c \
	  get_simplified_cmdln.c \

OBJ = ${SRC:.c=.o}

MAKE = make -C

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
