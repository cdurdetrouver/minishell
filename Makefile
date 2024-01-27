NAME = minishell
CC = cc
CFLAGS = -Wall -Werror -Wextra -I include/ -I libft/
LIBFT = -L libft -lft
SRC_DIR = ./src/
SRC = src/execute/builtin.c \
	src/execute/execute.c \
	src/execute/cmd/env.c \
	src/execute/cmd/unset.c \
	src/execute/cmd/cd.c \
	src/execute/cmd/export.c \
	src/execute/cmd/pwd.c \
	src/execute/cmd/echo.c \
	src/execute/cmd/exit.c \
	src/execute/execve.c \
	src/execute/pipe.c \
	src/execute/utils/here_doc.c \
	src/execute/utils/open.c \
	src/execute/utils/fd.c \
	src/main.c \
	src/parse/expand/expand_1.c \
	src/parse/expand/expand_3.c \
	src/parse/expand/expand_2.c \
	src/parse/token/token_1.c \
	src/parse/token/token_2.c \
	src/parse/token/token_3.c \
	src/parse/cmd/cmd_1.c \
	src/parse/cmd/cmd_4.c \
	src/parse/cmd/cmd_2.c \
	src/parse/cmd/cmd_3.c \
	src/parse/parsing/parsing_2.c \
	src/parse/parsing/parsing_1.c \
	src/parse/parsing/parsing_3.c \
	src/parse/str/str_2.c \
	src/parse/str/str_1.c \
	src/utils/prompt.c \
	src/utils/free.c \
	src/utils/envp2.c \
	src/utils/utils.c \
	src/utils/free2.c \
	src/utils/signal.c \
	src/utils/envp.c
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
	valgrind --suppressions=valgrind_readline_leaks_ignore.txt --leak-check=full --show-leak-kinds=all --track-fds=yes ./${NAME}

re: fclean all
