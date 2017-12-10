# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amasol <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 18:13:18 by amasol            #+#    #+#              #
#    Updated: 2017/12/05 13:21:18 by amasol           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit.a
CC = gcc
FLAG = -Wall -Wextra -Werror
SRS = 
OBJ = $(SRS:.c=.o)
HEADER =./fillit.h

all: $(NAME)

$(NAME): $(OBJ)


clean:
	rm -rf $(OBJ)
.c.o:
	$(CC) $(FLAG) -c $< -o $@
fclean: clean
	rm -rf $(NAME) $(OBJ)
re: fclean all
	
