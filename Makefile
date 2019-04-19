# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/16 16:14:57 by fabbenbr          #+#    #+#              #
#    Updated: 2019/04/09 18:04:27 by staeter          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC_PATH = srcs/
SRC = 			main.o \
				file_reader_fdf.o \
				file_reader_obj.o \
				errormessage.o \
				windows.o \

HOOK_PATH = srcs/hook/
HOOK =			key_press.o \
				mouse_press.o \
				close.o \
				mouse_move.o \
				expose.o \
				key_release.o \
				loop_hook.o

OBJ = 			$(addprefix $(SRC_PATH), $(SRC)) \
				$(addprefix $(HOOK_PATH), $(HOOK))

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

$(NAME): $(OBJ)
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
	@echo "$(PURPLE_E)$(NAME)\tcompiling$(END_E)"
	$(CC) -o $@ $^ $(LIB) $(FRAMEW)
	@echo "$(PURPLE_E)$(NAME)\tExecutable compiled$(END_E)"

all: $(NAME)

%.o:        %.c
	@$(CC) -c -o $@ $< $(INCLUDES) #$(CFLAGS)

clean:
	@$(MAKE) -C lib/libft/ clean
	@$(MAKE) -C lib/minilibx_macos/ clean
	@$(MAKE) -C lib/geolib/ clean
	@$(MAKE) -C lib/modelib/ clean
	@$(MAKE) -C lib/visualib/ clean
	@rm -f $(OBJ)
	@echo "$(YELLOW_E)$(NAME)\tclean$(END_E)"

fclean: clean
	@$(MAKE) -C lib/libft/ fclean
	@$(MAKE) -C lib/geolib/ fclean
	@$(MAKE) -C lib/modelib/ fclean
	@$(MAKE) -C lib/minilibx_macos/ fclean
	@$(MAKE) -C lib/visualib/ fclean
	@echo "$(RED_E)$(NAME)\tfclean$(END_E)"
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
