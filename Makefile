# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/03 01:35:34 by jurodrig          #+#    #+#              #
#    Updated: 2024/03/16 21:44:20 by jurodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

SOURCES = ft_putchar.c ft_putstr.c \
ft_putnbr.c ft_putunbr.c ft_putnbr_base.c \
ft_printf.c 

OBJ = $(SOURCES:.c=.o)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	
all: $(NAME)

.PHONY: all clean fclean re 

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

