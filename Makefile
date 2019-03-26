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

FLAGS = -Wall -Wextra

SRC_PATH = srcs/
SRC = 			$(SRC_PATH)main.c \
				$(SRC_PATH)windows.c \
				$(SRC_PATH)key_mouse_hook.c \
				$(SRC_PATH)file_reader.c \
				$(SRC_PATH)free.c \
				$(SRC_PATH)vemaker.c \
				$(SRC_PATH)vemaker2.c \
				$(SRC_PATH)keyboard.c \

OBJ = 			main.o \
				windows.o \
				key_mouse_hook.o \
				file_reader.o \
				free.o \
				vemaker.o \
				vemaker2.o \
				keyboard.o \

INCLUDES = 	-I includes/



FRAMEW = -framework OpenGL -framework AppKit

LIB = 	lib/minilibx_macos/libmlx.a \
		lib/libft/libft.a \
		lib/geolib/geolib.a \
		lib/modelib/modelib.a \
		lib/visualib/visualib.a \

END_E       = \033[00m
RED_E       = \033[01;31m
GREEN_E     = \033[01;32m
YELLOW_E    = \033[01;33m
PURPLE_E    = \033[01;35m
CYAN_E      = \033[01;36m
WHITE_E     = \033[01;37m
BOLD_E      = \033[1m
UNDERLINE_E = \033[4m


all: $(NAME)

$(NAME):
	@echo "$(PURPLE_E)$(NAME)\tCompiling libft$(END_E)"
	@$(MAKE) -C lib/libft/
	@echo "$(PURPLE_E)$(NAME)\tCompiling geolib$(END_E)"
	@$(MAKE) -C lib/geolib/
	@echo "$(PURPLE_E)$(NAME)\tCompiling minilibx$(END_E)"
	@$(MAKE) -C lib/minilibx_macos/
	@echo "$(PURPLE_E)$(NAME)\tCompiling modelib$(END_E)"
	@$(MAKE) -C lib/modelib/
	@echo "$(PURPLE_E)$(NAME)\tCompiling visualib$(END_E)"
	@$(MAKE) -C lib/visualib/
	@gcc -c $(SRC) $(INCLUDES) $(FLAGS)
	@echo "$(PURPLE_E)$(NAME)\tcompiling$(END_E)"
	@gcc -o $(NAME) $(OBJ) $(LIB) $(FRAMEW)
	@echo "$(PURPLE_E)$(NAME)\tExecutable compiled$(END_E)"

clean:
	@$(MAKE) -C lib/libft/ clean
	@$(MAKE) -C lib/minilibx_macos/ clean
	@$(MAKE) -C lib/geolib/ clean
	@$(MAKE) -C lib/modelib/ clean
	@$(MAKE) -C lib/visualib/ clean
	rm -f $(OBJ)
	@echo "$(YELLOW_E)$(NAME)\tclean$(END_E)"

fclean: clean
	@$(MAKE) -C lib/libft/ fclean
	@$(MAKE) -C lib/geolib/ fclean
	@$(MAKE) -C lib/modelib/ fclean
	@$(MAKE) -C lib/minilibx_macos/ fclean
	@$(MAKE) -C lib/visualib/ fclean
	@echo "$(RED_E)$(NAME)\tfclean$(END_E)"
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
