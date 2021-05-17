# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/16 18:54:00 by ahamdaou          #+#    #+#              #
#    Updated: 2021/05/17 19:04:56 by ahamdaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libexecution.a

CFLAGS = -Wall -Wextra -Werror \
		 -g \

CC = gcc

SRC = execute.c \

OBJ = ${SRC:.c=.o}

MAKE = make -C

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
