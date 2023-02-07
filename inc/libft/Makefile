# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 11:51:02 by ljerinec          #+#    #+#              #
#    Updated: 2022/10/31 11:51:23 by ljerinec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_strlen.c \
	ft_atoi_long_long.c \
	ft_atoi.c \
	ft_bzero.c \
	ft_isalpha.c \
	ft_isalnum.c \
	ft_isdigit.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_memset.c	\
	ft_memcpy.c	\
	ft_memmove.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c	\
	ft_strrchr.c \
	ft_strncmp.c \
	ft_strlcpy.c \
	ft_strdup.c \
	ft_memcmp.c \
	ft_memchr.c	\
	ft_strnstr.c \
	ft_strlcat.c \
	ft_calloc.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_substr.c	\
	ft_strjoin.c \
	ft_strtrim.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_itoa.c \
	ft_split.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelfirst.c \
	ft_lstdellast.c \

OBJECTS = $(SRC:.c=.o)
BONUS = $(SRC_BONUS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME) 

$(NAME): $(OBJECTS)
	$(AR) -rc $@ $?

bonus: $(BONUS)
	$(AR) -rc $(NAME) $?

clean:
	rm -f $(OBJECTS) $(BONUS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
