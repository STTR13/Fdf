# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/07 12:55:15 by fabbenbr          #+#    #+#              #
#    Updated: 2019/02/07 14:28:41 by fabbenbr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

INCLUDES = -I

LIB = libft.a

$(SRC) = ft_printf.c

$(OBJ) = ft_printf.o

all: $(NAME)

$(NAME):
	@$(MAKE) -C libft/
	gcc -c $(FLAGS) $(SRC) $(INCLUDES) $(LIB)
	ar -rcs $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	@$(MAKE) -C libft/ clean
	rm -f $(OBJ)

fclean:
	@$(MAKE) -C libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
