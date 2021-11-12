NAME = libx.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra \

SRC = libx.c \
	  libx_utils.c \
	  allocation.c \
	  alloc_fail.c \
	  swap.c \
	  utils.c \
	  xsubstr.c \
	  xrealloc.c \
	  xsplit.c \
	  xfree_str_array.c \
	  ft_atoi.c \
	  ft_isprint.c \
	  ft_memset.c \
	  ft_strdup.c \
	  ft_strnstr.c \
	  ft_strstr.c \
	  ft_bzero.c \
	  ft_itoa.c \
	  ft_putchar_fd.c \
	  ft_strjoin.c \
	  ft_strrchr.c \
	  ft_calloc.c \
	  ft_memccpy.c \
	  ft_putendl_fd.c \
	  ft_strlcat.c \
	  ft_strtrim.c \
	  ft_isalnum.c \
	  ft_memchr.c \
	  ft_putnbr_fd.c \
	  ft_strlcpy.c \
	  ft_substr.c \
	  ft_isalpha.c \
	  ft_memcmp.c \
	  ft_putstr_fd.c \
	  ft_putstr.c \
	  ft_strlen.c \
	  ft_tolower.c \
	  ft_isascii.c \
	  ft_memcpy.c \
	  ft_split.c \
	  ft_toupper.c \
	  ft_isdigit.c \
	  ft_memmove.c \
	  ft_strchr.c \
	  ft_strncmp.c \
	  ft_strcmp.c \
	  ft_dec2hex.c \
	  ft_strtoupper.c \
	  is_str_digit.c \
	  count_char.c \
	  length.c \
	  free_str_array.c \
	  ft_putc.c \
	  ft_max.c \
	  is_null.c \
	  not_null.c \
	  address_to_index.c \
	  setters.c \
	  getters.c \
	  del.c \
	  iterator.c \
	  is_empty.c \
	  string_array_to_string_list.c \
	  string_list_to_string_array.c \
	  replace_node_intolist.c \
	  is_not_empty.c \
	  deallocate.c \
	  ft_lsthas_next.c \
	  ft_lstrem.c \
	  join_string_array_to_string.c \
	  join_string_list_to_string.c \
	  join_string_list_with_nl.c \
	  debug_array_list.c \
	  splitat.c \
	  is_blank.c \
	  xitoa.c \
	  lstpush.c \
	  equal.c \

OBJ = ${SRC:.c=.o}

UNAME := $(shell uname -s)
ifeq ($(UNAME),Linux)
	CFLAGS += -fcommon
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
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME) $(NAME).dSYM

re:	fclean all
