# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 12:21:53 by gbazart           #+#    #+#              #
#    Updated: 2023/12/08 17:36:39 by gbazart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAG = -Wall -Wextra -Werror
OPTION = -c -I ./
SRC = *.c
OBJ = *.o

all: $(NAME)

$(NAME):
	cc $(FLAG) $(OPTION) $(SRC)
	ar rc $(NAME) $(OBJ)

clean:
	/bin/rm -f $(OBJ)
fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
