#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oltkache <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/17 14:09:37 by oltkache          #+#    #+#              #
#    Updated: 2018/02/17 14:09:38 by oltkache         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = players/oltkache.filler

SRC = main.c ft_coords.c ft_read.c ft_choice.c

OBJ = main.o ft_coords.o ft_read.o ft_choice.o

FLAGS = -Wall -Wextra -Werror

all: sub $(NAME)
	
sub:
	$(MAKE) -C ./libft

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) libft/libft.a

clean: subcl
	rm -f $(OBJ)

subcl:
	$(MAKE) -C ./libft clean

fclean: subf clean
	rm -f $(NAME)

subf:
	$(MAKE) -C ./libft fclean

re: fclean all

%.o : %.c
	gcc $(FLAGS) -c $<
	