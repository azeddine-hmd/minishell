NAME = minishell

CFLAGS = -Wall -Werror -Wextra \

CC = gcc

LIBS = execution/libexecution.a \
	   parser/libparser.a \
	   libx/libx.a \

SRC = minishell.c \
	  buffer.c \
	  errors.c \
	  terminal.c \
	  cursor.c \
	  input_key_first.c \
	  input_key_second.c \
	  heredoc.c \
	  heredoc_loop.c \
	  heredoc_entry.c \
	  usage.c \
	  history.c \
	  signal_interceptor.c \

OBJ = ${SRC:.c=.o}

MAKE = make --no-print-directory -C

UNAME := $(shell uname -s)
ifeq ($(UNAME),Linux)
	CFLAGS += -fcommon
	LDFLAGS += -lncurses
endif

ifeq ($(UNAME),Darwin)
	LDFLAGS += -ltermcap
endif

all: $(NAME) options

options:
	@echo ${NAME} build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"
	@echo

$(NAME):
	@$(MAKE) libx
	@$(MAKE) parser
	@$(MAKE) execution
	@$(CC) $(CFLAGS) $(SRC) $(LIBS) -o $(NAME) $(LDFLAGS)

clean:
	@$(MAKE) libx clean
	@$(MAKE) parser clean
	@$(MAKE) execution clean
	@rm -rf $(OBJ)

fclean: clean
	@$(MAKE) libx fclean
	@$(MAKE) parser fclean
	@$(MAKE) execution fclean
	@rm -rf $(NAME) $(NAME).dSYM

re: fclean all

.PHONY: clean fclean re
