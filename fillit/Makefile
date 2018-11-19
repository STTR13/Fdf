# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/19 12:20:29 by fabbenbr          #+#    #+#              #
#    Updated: 2018/11/19 12:37:12 by fabbenbr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC_PATH = srcs/

INCLUDES = -I includes/

LIB = Libft/libft.a

FLAGS = -Wall -Werror -Wextra

SRC = $(SRC_PATH)main.c

OBJ = main.o

all: $(NAME)

$(NAME):
	gcc -c $(SRC) $(FLAGS) $(INCLUDES)
	gcc -o $(NAME) $(OBJ) $(LIB)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
