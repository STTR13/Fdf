# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/16 16:14:57 by fabbenbr          #+#    #+#              #
#    Updated: 2018/11/17 13:29:47 by fabbenbr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_PATH = srcs/

SRC = main.c \
				$(SRC_PATH)key_mouse_hook.c

OBJ = main.o \
				$(SRC_PATH)/key_mouse_hook.o

INCLUDES = /includes

FRAMEW = -framework OpenGL -framework AppKit

LIB = minilibx_macos/libmlx.a libft/libft.a

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -I $(INCLUDES)  $(LIB) $(FRAMEW)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
