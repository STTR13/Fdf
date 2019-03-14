# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/16 16:14:57 by fabbenbr          #+#    #+#              #
#    Updated: 2019/01/18 11:05:53 by fabbenbr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_PATH = srcs/

SRC = 			$(SRC_PATH)main.c \
				$(SRC_PATH)windows.c \
				$(SRC_PATH)key_mouse_hook.c \
				$(SRC_PATH)file_reader.c \
				$(SRC_PATH)free.c \
				$(SRC_PATH)vemaker.c \

OBJ = 			main.o \
				windows.o \
				key_mouse_hook.o \
				file_reader.o \
				free.o \
				vemaker.o \

INCLUDES = includes/


FRAMEW = -framework OpenGL -framework AppKit

LIB = 	lib/minilibx_macos/libmlx.a \
		lib/libft/libft.a \
		lib/geolib/geolib.a \
		lib/modelib/modelib.a \


FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@$(MAKE) -C lib/libft/
	@$(MAKE) -C lib/geolib/
	@$(MAKE) -C lib/minilibx_macos/
	@$(MAKE) -C lib/modelib/
	gcc -c $(SRC) -I $(INCLUDES) $(FLAGS)
	gcc -o $(NAME) $(OBJ) $(LIB) $(FRAMEW)

clean:
	@$(MAKE) -C lib/libft/ clean
	@$(MAKE) -C lib/minilibx_macos/ clean
	@$(MAKE) -C lib/geolib/ clean
	@$(MAKE) -C lib/modelib/ clean
	rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C lib/libft/ fclean
	@$(MAKE) -C lib/geolib/ fclean
	@$(MAKE) -C lib/modelib/ fclean
	@$(MAKE) -C lib/minilibx_macos/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
