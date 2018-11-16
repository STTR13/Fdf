# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/16 15:18:01 by fabbenbr          #+#    #+#              #
#    Updated: 2018/11/16 15:41:23 by fabbenbr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c

OBJ = main.o

INCLUDES = /usr/local/include

LIB = /usr/local/lib

//FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -I $(INCLUDES) -L $(LIB) minilibx_macos/libmlx.a -framework OpenGL -framework AppKit
	

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
