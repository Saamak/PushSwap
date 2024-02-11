# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 16:43:36 by ppitzini          #+#    #+#              #
#    Updated: 2024/02/11 18:23:54 by ppitzini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 	   = errors_args \
			 push_swap \
			 utils \
			 utils_two \
			 checks_args \
			 swap_push \
			 free_funct \
			 sort_algorythm \
			 simple_sort \
			 rotate \

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror -g

EXEC	= push_swap

CFILES	= $(SRC:%=%.c)

OBJ	= $(SRC:=.o)

NAME = $(EXEC)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
