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

CC = gcc
CFLAGS = -Wall -Wextra -Werror

INCLUDES = ./includes

SRC_PATH = srcs/
SRC = ft_atoi.o \
	  ft_bzero.o \
	  ft_isalnum.o \
	  ft_isalpha.o \
	  ft_isascii.o \
	  ft_isdigit.o \
	  ft_isprint.o \
	  ft_itoa.o \
	  ft_memalloc.o \
	  ft_memccpy.o \
	  ft_memchr.o \
	  ft_memcmp.o \
	  ft_memcpy.o \
	  ft_memdel.o \
	  ft_memmove.o \
	  ft_memset.o \
	  ft_putchar.o \
	  ft_putchar_fd.o \
	  ft_putendl.o \
	  ft_putendl_fd.o \
	  ft_putnbr.o \
	  ft_putnbr_fd.o \
	  ft_putstr.o \
	  ft_putstr_fd.o \
	  ft_strcat.o \
	  ft_strchr.o \
	  ft_strclr.o \
	  ft_strcmp.o \
	  ft_strcpy.o \
	  ft_strdel.o \
	  ft_strdup.o \
	  ft_strequ.o \
	  ft_striter.o \
	  ft_striteri.o \
	  ft_strjoin.o \
	  ft_strlcat.o \
	  ft_strlen.o \
	  ft_strmap.o \
	  ft_strmapi.o \
	  ft_strncat.o \
	  ft_strncmp.o \
	  ft_strncpy.o \
	  ft_strnequ.o \
	  ft_strnew.o \
	  ft_strnstr.o \
	  ft_strrchr.o \
	  ft_strsplit.o \
	  ft_strstr.o \
	  ft_strsub.o \
	  ft_strtrim.o \
	  ft_tolower.o \
	  ft_toupper.o \
		ft_lstnew.o \
		ft_lstdelone.o \
		ft_lstdel.o \
		ft_lstadd.o \
		ft_lstiter.o \
		ft_lstmap.o \
		ft_strdel_neg.o \
		ft_chararrclr.o \
		ft_intarrclr.o \
		get_next_line.o \
		ft_strcatn.o \
		ft_strjoinn.o \
		ft_intarrprint.o \
		ft_memdell.o \
		ft_strdell.o \
		ft_hexaconverter.o \
		ft_ishexa.o \
		ft_strjoinspace.o \

OBJ = $(addprefix $(SRC_PATH), $(SRC))

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
		@ar -rcs $@ $^
		@echo "$(GREEN_E)$(NAME)\tCompiled$(END_E)"
		ranlib $(NAME)

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $< -I $(INCLUDES)

clean:
	@rm -f $(OBJ)
	@echo "$(YELLOW_E)$(NAME)\tclean$(END_E)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED_E)$(NAME)\tfclean$(END_E)"

re: fclean all

.PHONY: clean fclean all re
