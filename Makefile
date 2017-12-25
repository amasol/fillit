# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amasol <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 18:13:18 by amasol            #+#    #+#              #
#    Updated: 2017/12/25 16:43:01 by amasol           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
FLAG = -Wall -Wextra -Werror
SRS = ft_check.c ft_termin.c ft_putstr.c ft_putchar.c main.c
OBJ = $(SRS:.c=.o)
HEADER = .fillit.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAG) -c $(SRS) -I $(HEADER)
	$(CC) -o $(NAME) $(OBJ)
clean:
	rm -rf $(OBJ)
.c.o:
	$(CC) $(FLAG) -c $< -o $@
fclean: clean
	rm -rf $(NAME) $(OBJ)
re: fclean all
	
