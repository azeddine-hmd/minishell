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
	  usage.c \
	  history.c \
	  cursor.c \
	  heredoc.c \
	  heredoc_loop.c \
	  heredoc_entry.c \
	  heredoc_extra.c \
	  hd_enter_triggered.c \
	  signal_interceptor.c \
	  backspace_triggered.c \
	  arrows_triggered.c \
	  ctrl_d_triggered.c \
	  enter_triggered.c \
	  ctrl_l_triggered.c \
	  tsettings.c \

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

all: $(NAME)

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
