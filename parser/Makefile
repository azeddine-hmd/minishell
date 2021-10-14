NAME = libparser.a

CFLAGS = -Wall -Wextra -Werror \
		 -g \

CC = gcc

SRC = parse.c \
	  cmdslst.c \
	  parse_debugger.c \
	  parse_debugger_2.c \
	  check_syntax_err.c \
	  create_cmds.c \
	  get_quotes_range.c \
	  range.c \
	  quotes.c \
	  token.c \
	  split_except_quotes.c \
	  get_simplified_cmdln.c \
	  separate_quotes.c \
	  separate_tokens.c \
	  tkindx_del.c \
	  get_tokens_range.c \
	  is_token.c \
	  add_token_to_cmd.c \
	  cmd_del.c \
	  envindx.c \
	  expand.c \

OBJ = ${SRC:.c=.o}

MAKE = make -C

all: options $(NAME)

options:
	@echo ${NAME} build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"
	@echo

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) $(NAME).dSYM

re: fclean all

.PHONY: clean fclean re
