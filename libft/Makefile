NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror \
		 -g \

SRC = ft_atoi.c \
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
	  is_not_null.c \

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
