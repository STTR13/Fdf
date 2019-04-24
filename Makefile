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
INCLUDES = 	includes/
FRAMEW = -framework OpenGL -framework AppKit



SRC_PATH = srcs/
SRC = 			main.o \
				file_reader_fdf.o \
				file_reader_obj.o \
				errormessage.o \
				windows.o \
				reader.o \
				opti_gnl.o

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



MLX_PATH = 	lib/minilibx_macos/
MLX =			libmlx.a

LFT_PATH = 	lib/libft/
LFT =			libft.a

GEO_PATH = 	lib/geolib/
GEO =			geolib.a

MOD_PATH = 	lib/modelib/
MOD =			modelib.a

VIS_PATH = 	lib/visualib/
VIS =			visualib.a

ALL_LIB_PATH =	$(MLX_PATH) \
				$(LFT_PATH) \
				$(GEO_PATH) \
				$(MOD_PATH) \
				$(VIS_PATH)
LIB =			$(addprefix $(MLX_PATH), $(MLX)) \
				$(addprefix $(LFT_PATH), $(LFT)) \
				$(addprefix $(GEO_PATH), $(GEO)) \
				$(addprefix $(MOD_PATH), $(MOD)) \
				$(addprefix $(VIS_PATH), $(VIS))



END_E       = \033[00m
RED_E       = \033[01;31m
GREEN_E     = \033[01;32m
YELLOW_E    = \033[01;33m
PURPLE_E    = \033[01;35m
CYAN_E      = \033[01;36m
WHITE_E     = \033[01;37m
BOLD_E      = \033[1m
UNDERLINE_E = \033[4m



$(NAME): $(OBJ) $(LIB)
	@$(CC) -o $@ $^ $(FRAMEW) -I $(INCLUDES) $(CFLAGS)
	@echo "$(PURPLE_E)$(NAME)\t\tcompile$(END_E)"

all: $(NAME)

%.a:
	@$(MAKE) -C $(@D)/

%.o:        %.c
	@$(CC) -c -o $@ $< -I $(INCLUDES) $(CFLAGS)

clean:
	@$(MAKE) clean -C lib/libft/
	@$(MAKE) clean -C lib/minilibx_macos/
	@$(MAKE) clean -C lib/geolib/
	@$(MAKE) clean -C lib/modelib/
	@$(MAKE) clean -C lib/visualib/
	@rm -f $(OBJ)
	@echo "$(PURPLE_E)$(NAME)\t\tclean$(END_E)"

fclean:
	@$(MAKE) fclean -C lib/libft/
	@$(MAKE) fclean -C lib/geolib/
	@$(MAKE) fclean -C lib/modelib/
	@$(MAKE) fclean -C lib/minilibx_macos/
	@$(MAKE) fclean -C lib/visualib/
	@echo "$(PURPLE_E)$(NAME)\t\tfclean$(END_E)"
	@rm -f $(OBJ) $(NAME)

re: fclean all

.PHONY: clean fclean all re lib
