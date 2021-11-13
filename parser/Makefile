NAME = libparser.a

CFLAGS = -Wall -Wextra -Werror \

CC = gcc

SRC = parse.c \
	  check_syntax_err.c \
	  create_cmds.c \
	  get_quotes_range.c \
	  range.c \
	  quotes.c \
	  token.c \
	  split_except_quotes.c \
	  get_simplified_cmdln.c \
	  separate_tokens.c \
	  tkindx_del.c \
	  get_tokens_range.c \
	  is_token.c \
	  add_token_to_cmd.c \
	  cmd_del.c \
	  envindx.c \
	  expand.c \
	  pa_getenv.c \
	  strip_quotes.c \
	  check_valid_files.c \
	  getret.c \
	  strip_side_quotes.c \
	  restore_expanded_tokens.c \
	  token_change.c \

OBJ = ${SRC:.c=.o}

MAKE = make -C

UNAME := $(shell uname -s)
ifeq ($(UNAME),Linux)
	CFLAGS += -fcommon
endif

ifeq ($(UNAME),Darwin)
endif

all: $(NAME)

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
