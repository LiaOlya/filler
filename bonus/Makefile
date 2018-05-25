#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oltkache <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/26 18:25:09 by oltkache          #+#    #+#              #
#    Updated: 2018/04/26 18:25:10 by oltkache         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME1 = ../vizual

NAME2 = ../run_all

SRC = viz1.c vizualizer.c

OBJ1 = viz1.o vizualizer.o

OBJ2 = run.o

FLAGS = -Wall -Wextra -Werror

all: sub $(NAME1) $(NAME2)
	
sub:
	$(MAKE) -C ./../libft

$(NAME1): $(OBJ1)
	gcc -o $(NAME1) $(OBJ1) ../libft/libft.a

$(NAME2): $(OBJ2)
	gcc -o $(NAME2) $(OBJ2) ../libft/libft.a

clean: subcl
	rm -f $(OBJ1)
	rm -f $(OBJ2)

subcl:
	$(MAKE) -C ./../libft clean

fclean: subf clean
	rm -f $(NAME1)
	rm -f $(NAME2)

subf:
	$(MAKE) -C ./../libft fclean

re: fclean all

%.o : %.c
	gcc $(FLAGS) -c $<
	