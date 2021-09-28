NAME = minishell

CFLAGS = -Wall -Werror -Wextra \
		 -g \
		 -fsanitize=address \

CC = gcc

LIBS = libft/libft.a \
	   libx/libx.a \
	   linkedlist/liblinkedlist.a \
	   parser/libparser.a \
	   execution/libexecution.a \

SRC = minishell.c \
	  errors.c \
	  terminal.c \
	  cursor.c \
	  buffer.c \

UNAME := $(shell uname -s)

ifeq ($(UNAME),Linux)
	LDFLAGS += -lncurses
endif

ifeq ($(UNAME),Darwin)
	LDFLAGS += -ltermcap
endif

OBJ = ${SRC:.c=.o}

MAKE = make --no-print-directory -C

all: options $(NAME)

options:
	@echo ${NAME} build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"

$(NAME):
	@$(MAKE) libft
	@$(MAKE) libx
	@$(MAKE) linkedlist
	@$(MAKE) parser
	@$(MAKE) execution
	@$(CC) $(CFLAGS) -c $(SRC)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME) $(LDFLAGS)

clean:
	@$(MAKE) libft clean
	@$(MAKE) libx clean
	@$(MAKE) linkedlist clean
	@$(MAKE) parser clean
	@$(MAKE) execution clean
	@rm -rf $(OBJ)

fclean:
	@$(MAKE) libft fclean
	@$(MAKE) libx fclean
	@$(MAKE) linkedlist fclean
	@$(MAKE) parser fclean
	@$(MAKE) execution fclean
	@rm -rf $(NAME) $(NAME).dSYM #TODO: remove .dSYM

re: fclean all

.PHONY: clean fclean re
