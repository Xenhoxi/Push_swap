# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 16:44:58 by ljerinec          #+#    #+#              #
#    Updated: 2023/02/26 02:13:14 by ljerinec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = src/push_swap.c \
	src/parsing/parsing.c \
	src/parsing/parsing_2.c \
	src/linked_list/stack_gestion.c \
	src/linked_list/stack_gestion_2.c \
	src/instructions/swap.c \
	src/instructions/push.c \
	src/instructions/reverse_rotate.c \
	src/instructions/rotate.c \
	src/sorting/sorting_utils.c \
	src/sorting/sorting_3.c \
	src/sorting/sorting_5.c \
	src/sorting/sorting_100.c \
	src/sorting/sorting_500.c \

CC = gcc

OBJECTS = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

all: $(NAME) 

$(NAME): $(OBJECTS)
	make -C inc/libft
	gcc $(CFLAGS) -o $(NAME) $(OBJECTS) inc/libft/libft.a -g3

clean:
	rm -f $(OBJECTS) $(BONUS)
	make -C inc/libft clean

fclean: clean
	/bin/rm -f $(NAME)
	rm -f $(OBJECTS)
	make -C inc/libft fclean

re: fclean all