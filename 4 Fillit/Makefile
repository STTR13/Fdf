# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/19 12:20:29 by fabbenbr          #+#    #+#              #
#    Updated: 2018/12/02 15:46:50 by fabbenbr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC_PATH = srcs/

INCLUDES = -I includes/

LIB = Libft/libft.a

FLAGS = -Wall -Werror -Wextra

SRC = $(SRC_PATH)main.c \
				$(SRC_PATH)ft_file_reader.c \
				$(SRC_PATH)ft_errorchecker.c \
				$(SRC_PATH)ft_cluster_maker.c \
				$(SRC_PATH)ft_solver.c \
				$(SRC_PATH)ft_find_size.c \
				$(SRC_PATH)ft_printmap.c \
				$(SRC_PATH)ft_leak_cleaner.c \


OBJ = main.o \
				ft_file_reader.o \
				ft_errorchecker.o \
				ft_cluster_maker.o \
				ft_solver.o \
				ft_find_size.o \
				ft_printmap.o \
				ft_leak_cleaner.o \

all: $(NAME)

$(NAME):
	@$(MAKE) -C Libft/
	gcc -c $(SRC) $(INCLUDES)
	gcc -o $(NAME) $(OBJ) $(LIB)

clean:
	@$(MAKE) -C Libft/ clean
	rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C Libft/ fclean
	rm -f $(NAME) $(LIB)

re: fclean all

.PHONY: clean fclean all re
