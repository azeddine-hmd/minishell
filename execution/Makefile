NAME = libexecution.a

CFLAGS = -Wall -Wextra -Werror \
		 -g \

CC = gcc

SRC = execute.c  main.c utils_0.c utils_1.c env.c pwd.c export.c \
	  unset.c cd.c echo.c pipes.c redirections.c exit.c \

OBJ = ${SRC:.c=.o}

MAKE = make -C

UNAME := $(shell uname -s)
ifeq ($(UNAME),Linux)
	CFLAGS += -fcommon -Wno-nonnull
endif

ifeq ($(UNAME),Darwin)
endif

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
	@rm -rf $(NAME) $(NAME).dSY

re: fclean all

.PHONY: clean fclean re