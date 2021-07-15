NAME = libx.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra \
		 -g \

SRC = libx.c \
	  libx_utils.c \
	  allocation.c \
	  alloc_fail.c \
	  swap.c \
	  utils.c \
	  xsubstr.c \
	  xrealloc.c \
	  xsplit.c \

OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME):
	@ $(CC) $(CFLAGS) -c $(SRC)
	@ ar rc $(NAME) $(OBJ)

clean:
	@ rm -f $(OBJ)

fclean: clean
	@ rm -f $(NAME)

re:	fclean all
