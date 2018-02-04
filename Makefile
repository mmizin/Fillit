#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahonchar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 17:33:57 by ahonchar          #+#    #+#              #
#    Updated: 2018/01/24 14:29:46 by ahonchar         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit
FLAGS = -Wextra -Wall -Werror
SRC = main.c print_map.c list.c valid.c map_size.c count_tetr.c
OBJ = main.o print_map.o list.o valid.o map_size.o count_tetr.o
INC = fillit.h

all: $(NAME)

%.o:%.c
	gcc $(FLAGS) -c $^

$(NAME): $(OBJ)
	gcc $(FLAGS) $(OBJ) -o $(NAME)

clean:
	/bin/rm -rf *~
	/bin/rm -rf *.o

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean $(NAME)