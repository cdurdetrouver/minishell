NAME = minishell
CC = cc
CFLAGS = -Wall -Werror -Wextra -I include/ -I libft/
LIBFT = -L libft -lft
SRC_DIR = ./src/
SRC = $(shell find $(SRC_DIR) -type f -name "*.c")
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\n"
	@make -s -C libft/
	@echo "\033[0;32mCompiling minishell..."
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -lreadline -lm -o $(NAME)
	@echo "\n\033[0mDone !"

%.o: %.c
	@printf "\033[0;33mGenerating minishell objects... %-33.33s\r" $@
	@${CC} ${CFLAGS} -g -c $< -o $@

norminette:
	norminette $(SRC_DIR)
	norminette ./include/

clean:
	@$(MAKE) -s clean -C ./libft
	@/bin/rm -f $(OBJ)

fclean: clean
	@$(MAKE) -s fclean -C ./libft
	@/bin/rm -f $(NAME)

valgrind : all
	valgrind --leak-check=full --track-origins=yes --track-fds=all --trace-children=yes ./$(NAME)

re: fclean all
