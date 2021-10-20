NAME = libexecution.a

CFLAGS = -Wall -Wextra -Werror \
		 -g \
		 -DDEBUG \

CC = gcc

SRC = execute.c \

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
	@rm -rf $(NAME) $(NAME).dSY

re: fclean all

.PHONY: clean fclean re
