# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: staeter <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/05 14:37:36 by staeter           #+#    #+#              #
#    Updated: 2019/03/05 14:37:42 by staeter          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = geolib.a



CC = gcc
CFLAGS = -Wall -Wextra -Werror



INCLUDES = ./includes

MATRIX_PATH = matrix/
MATRIX =	inverse.o \
			product.o \
			specialvalues.o

PLAN_PATH = plan/
PLAN =		ordinatesystem.o \
			projection.o \
			rotation.o

VECTOR_PATH = vector/
VECTOR =	basicvalues.o \
			booleans.o \
			norm.o \
			product.o \
			sum.o \
			manip.o

OBJ =	$(addprefix $(MATRIX_PATH), $(MATRIX)) \
		$(addprefix $(PLAN_PATH), $(PLAN)) \
		$(addprefix $(VECTOR_PATH), $(VECTOR))



END_E       = \033[00m
RED_E       = \033[01;31m
GREEN_E     = \033[01;32m
YELLOW_E    = \033[01;33m
PURPLE_E    = \033[01;35m
CYAN_E      = \033[01;36m
WHITE_E     = \033[01;37m
BOLD_E      = \033[1m
UNDERLINE_E = \033[4m



$(NAME):	$(OBJ)
			@ar -rcs $@ $^
			@echo "$(GREEN_E)$(NAME)\tcompile$(END_E)"

all:		$(NAME)

%.o:        %.c
			@$(CC) $(CFLAGS) -c -o $@ $< -I$(INCLUDES)

clean:
			@rm -f $(OBJ)
			@echo "$(YELLOW_E)$(NAME)\tclean$(END_E)"

fclean:		clean
			@rm -f $(NAME)
			@echo "$(RED_E)$(NAME)\tfclean$(END_E)"

re: 		fclean all

.PHONY: clean fclean all re
