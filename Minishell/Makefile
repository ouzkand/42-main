NAME = minishell
CC = gcc
FLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -lreadline
LIBFT = libft/libft.a
SRC = src/main.c \
	  src/signal.c \
	  src/lexer/lexer.c \
	  src/lexer/skip.c \
	  src/lexer/control.c \
	  src/lexer/utils.c \
	  src/lexer/add_token.c \
	  src/lexer/parser.c \
	  src/lexer/add_dolar.c \
	  src/lexer/parser_utils.c \
	  src/utils/utils_directory.c \
	  src/utils/free_all.c \
	  src/utils/linked_list_utils.c \
	  src/utils/is_builtin.c\
	  src/utils/ft_strcmp.c\
	  src/utils/init.c\
	  src/exec/exec_cmnd.c \
	  src/exec/exec_utils.c \
	  src/exec/utils.c \
	  src/exec/get_paths.c \
	  src/exec/dup2_scale.c \
	  src/exec/close_wait.c \
	  src/exec/input_output.c \
	  src/exec/linked_list_utils.c \
	  src/builtin/export.c	\
	  src/builtin/unset.c	\
	  src/builtin/builtins.c \
	  src/builtin/cd.c \
	  src/builtin/free_double.c \
	  src/builtin/keyvals.c  \
	  src/builtin/ft_echo.c\
	  src/builtin/exit_utils.c  \
	  src/builtin/environment_utils.c \
	  src/builtin/environment.c \
	  src/builtin/utils.c \

all: $(NAME)

$(NAME): $(SRC) $(LIBFT)
	$(CC) $(FLAGS) $(SRC) $(LIBFT) $(LDFLAGS)  -o $(NAME)

$(LIBFT):
	make -C libft/

clean:
	rm -rf minishell
	make clean -C libft/

fclean:
	rm -rf minishell
	make fclean -C libft/

re: fclean all
