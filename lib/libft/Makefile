# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/13 14:22:54 by fabbenbr          #+#    #+#              #
#    Updated: 2018/10/15 10:45:52 by fabbenbr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_PATH = srcs/

INCLUDES = -I includes/

SRC = $(SRC_PATH)ft_atoi.c \
	  $(SRC_PATH)ft_bzero.c \
	  $(SRC_PATH)ft_isalnum.c \
	  $(SRC_PATH)ft_isalpha.c \
	  $(SRC_PATH)ft_isascii.c \
	  $(SRC_PATH)ft_isdigit.c \
	  $(SRC_PATH)ft_isprint.c \
	  $(SRC_PATH)ft_itoa.c \
	  $(SRC_PATH)ft_memalloc.c \
	  $(SRC_PATH)ft_memccpy.c \
	  $(SRC_PATH)ft_memchr.c \
	  $(SRC_PATH)ft_memcmp.c \
	  $(SRC_PATH)ft_memcpy.c \
	  $(SRC_PATH)ft_memdel.c \
	  $(SRC_PATH)ft_memmove.c \
	  $(SRC_PATH)ft_memset.c \
	  $(SRC_PATH)ft_putchar.c \
	  $(SRC_PATH)ft_putchar_fd.c \
	  $(SRC_PATH)ft_putendl.c \
	  $(SRC_PATH)ft_putendl_fd.c \
	  $(SRC_PATH)ft_putnbr.c \
	  $(SRC_PATH)ft_putnbr_fd.c \
	  $(SRC_PATH)ft_putstr.c \
	  $(SRC_PATH)ft_putstr_fd.c \
	  $(SRC_PATH)ft_strcat.c \
	  $(SRC_PATH)ft_strchr.c \
	  $(SRC_PATH)ft_strclr.c \
	  $(SRC_PATH)ft_strcmp.c \
	  $(SRC_PATH)ft_strcpy.c \
	  $(SRC_PATH)ft_strdel.c \
	  $(SRC_PATH)ft_strdup.c \
	  $(SRC_PATH)ft_strequ.c \
	  $(SRC_PATH)ft_striter.c \
	  $(SRC_PATH)ft_striteri.c \
	  $(SRC_PATH)ft_strjoin.c \
	  $(SRC_PATH)ft_strlcat.c \
	  $(SRC_PATH)ft_strlen.c \
	  $(SRC_PATH)ft_strmap.c \
	  $(SRC_PATH)ft_strmapi.c \
	  $(SRC_PATH)ft_strncat.c \
	  $(SRC_PATH)ft_strncmp.c \
	  $(SRC_PATH)ft_strncpy.c \
	  $(SRC_PATH)ft_strnequ.c \
	  $(SRC_PATH)ft_strnew.c \
	  $(SRC_PATH)ft_strnstr.c \
	  $(SRC_PATH)ft_strrchr.c \
	  $(SRC_PATH)ft_strsplit.c \
	  $(SRC_PATH)ft_strstr.c \
	  $(SRC_PATH)ft_strsub.c \
	  $(SRC_PATH)ft_strtrim.c \
	  $(SRC_PATH)ft_tolower.c \
	  $(SRC_PATH)ft_toupper.c \
		$(SRC_PATH)ft_lstnew.c \
		$(SRC_PATH)ft_lstdelone.c \
		$(SRC_PATH)ft_lstdel.c \
		$(SRC_PATH)ft_lstadd.c \
		$(SRC_PATH)ft_lstiter.c \
		$(SRC_PATH)ft_lstmap.c \
		$(SRC_PATH)ft_strdel_neg.c \
		$(SRC_PATH)ft_chararrclr.c \
		$(SRC_PATH)ft_intarrclr.c \
		$(SRC_PATH)get_next_line.c \
		$(SRC_PATH)ft_strcatn.c \
		$(SRC_PATH)ft_strjoinn.c \
		$(SRC_PATH)ft_intarrprint.c \
		$(SRC_PATH)ft_memdell.c \
		$(SRC_PATH)ft_strdell.c \
		$(SRC_PATH)ft_hexaconverter.c \
		$(SRC_PATH)ft_ishexa.c \
		$(SRC_PATH)ft_strjoinspace.c \

OBJ = *.o

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
		gcc -c $(FLAGS) $(SRC) $(INCLUDES)
		ar -r $(NAME) $(OBJ)
		ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
