NAME = minishell

CFLAGS = -Wall -Werror -Wextra \
		 -g \
		 -fsanitize=address \
		 -DDEBUG \

CC = gcc

LIBS = parser/libparser.a \execution/libexecution.a \
	   libx/libx.a \

SRC = minishell.c \
	  buffer.c \
	  errors.c \
	  terminal.c \
	  cursor.c \
	  input_key_first.c \

OBJ = ${SRC:.c=.o}

MAKE = make --no-print-directory -C

UNAME := $(shell uname -s)

ifeq ($(UNAME),Linux)
	LDFLAGS += -lncurses
endif

ifeq ($(UNAME),Darwin)
	LDFLAGS += -ltermcap
endif

all: options $(NAME)

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
	rm -rf $(NAME) $(NAME).dSYM

re: fclean all

.PHONY: clean fclean re
