# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 16:44:58 by ljerinec          #+#    #+#              #
#    Updated: 2023/01/21 00:57:19 by ljerinec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = src/push_swap.c \
	src/parsing.c \

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME) 

$(NAME): $(OBJECTS)
	gcc -Wall -Wextra -Werror $(SRC) inc/libft/libft.a -g3

clean:
	rm -f $(OBJECTS) $(BONUS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all