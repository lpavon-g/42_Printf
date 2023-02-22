# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpavon-g <lpavon-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/17 18:27:04 by lpavon-g          #+#    #+#              #
#    Updated: 2023/02/20 23:24:11 by lpavon-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra
CC = gcc
SRC = ft_printf.c ft_printwords.c ft_printnumbers.c
OBJS = $(SRC:.c=.o)

HEADER: ft_printf.h

all: $(NAME)

$(NAME): $(OBJS)
	ar -crs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

