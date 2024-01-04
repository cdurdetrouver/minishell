NAME = minishell
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
LIBFT = ./libft/libft.a
SRC_DIR = ./src/
SRC = $(wildcard $(SRC_DIR)*.c) $(wildcard $(SRC_DIR)parse/*.c) $(wildcard $(SRC_DIR)execute/*.c) $(wildcard $(SRC_DIR)utils/*.c)
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) -lreadline -lm $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

norminette:
	norminette $(SRC_DIR)
	norminette ./includes/

clean:
	$(MAKE) clean -C ./libft
	/bin/rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	/bin/rm -f $(NAME)

re: fclean all