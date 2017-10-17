# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/27 13:51:53 by fpasquer          #+#    #+#              #
#    Updated: 2017/10/17 14:57:24 by fpasquer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfts.a
ASM = nasm
FLAGS = -f macho64 -g
SRC = ft_bzero.s ft_strcat.s ft_isalpha.s ft_strncat.s ft_isdigit.s ft_isalnum.s	\
	  ft_isascii.s ft_isprint.s ft_toupper.s ft_tolower.s ft_strlen.s ft_putstr.s	\
	  ft_puts.s ft_memset.s ft_memcpy.s ft_strdup.s ft_strjoin.s ft_memdel.s		\
	  ft_strchr.s ft_strrchr.s ft_strcpy.s ft_strncpy.s ft_cat.s ft_strcmp.s


OBJ = $(SRC:.s=.o)

all: $(NAME)

$(NAME) : $(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

%.o: %.s
	$(ASM) $(FLAGS) $< -o  $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
