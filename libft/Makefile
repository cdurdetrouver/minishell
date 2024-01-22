# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 12:21:53 by gbazart           #+#    #+#              #
#    Updated: 2024/01/22 14:20:42 by gbazart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAG = -Wall -Wextra -Werror
OPTION = -I ./
SRC = ft_isdigit.c \
	ft_atoll.c \
    ft_strcmp.c \
    ft_lstadd_back.c \
    ft_putendl_fd.c \
    ft_lstmap.c \
    ft_memmove.c \
    ft_isascii.c \
    ft_atoi.c \
    ft_putnbr.c \
    get_next_line.c \
    ft_isalpha.c \
    ft_putchar.c \
    ft_memset.c \
    ft_split.c \
    ft_putstr_fd.c \
    ft_memchr.c \
    ft_strtrim.c \
    ft_strnstr.c \
    ft_putu.c \
    ft_lstadd_front.c \
    ft_isspace.c \
    ft_strlen.c \
    ft_lstclear.c \
    ft_lstnew.c \
    ft_strlcpy.c \
    ft_putptr.c \
    ft_memcpy.c \
    ft_strlcat.c \
    ft_strrchr.c \
    ft_itoa.c \
    ft_isnumeric.c \
    ft_isalnum.c \
    ft_putnbr_fd.c \
    ft_calloc.c \
    ft_lstdelone.c \
    ft_bzero.c \
    ft_strncmp.c \
    ft_atol.c \
    ft_strchr.c \
    ft_striteri.c \
    ft_lstiter.c \
    ft_isprint.c \
    ft_atodbl.c \
    ft_puthex.c \
    ft_putstr.c \
    ft_strdup.c \
    ft_putchar_fd.c \
    ft_toupper.c \
    ft_lstlast.c \
    ft_strjoin.c \
    ft_lstsize.c \
    ft_strmapi.c \
    ft_memcmp.c \
    ft_printf.c \
    ft_substr.c \
    ft_tolower.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	cc $(FLAG) $(OPTION) -c $< -o $@

clean:
	/bin/rm -f $(OBJ)
fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
