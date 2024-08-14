# Program name
NAME	=  minishell

# Compiler options
CC		= cc -g
CFLAGS	= -Wall -Wextra -Werror

#libft
LIBFT_DIR := ./libft/
LIBFT_SRCS := $(wildcard $(LIBFT_DIR)*.c)
LIBFT_OBJS := $(patsubst $(LIBFT_DIR)%.c, $(LIBFT_DIR)%.o, $(LIBFT_SRCS))

SRC		= 	src/init.c \
			src/main.c \
			src/builtins/cd_builtins.c \
			src/builtins/echo_builtins.c \
			src/builtins/env_builtins.c \
			src/builtins/exit_builtins.c \
			src/builtins/pwd_builtins.c \
			src/builtins/unset_builtins.c \
			src/builtins/export_builtins.c \
			src/builtins/run_builtins.c \
			src/pipex/pipex.c \
			src/pipex/gnl_function.c \
			src/pipex/gnl_utils.c \
			src/pipex/gnl.c \
			src/run/run_builtins.c \
			src/run/run_exec.c \
			src/free.c \

	
	
OBJ		= $(SRC:.c=.o)

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

$(LIBFT_OBJS): $(LIBFT_SRCS)
	@make -C $(LIBFT_DIR)

# Compiling minishell
$(NAME): $(OBJ) $(LIBFT_OBJS)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT_OBJS) -lreadline
	@echo "  "
	@echo "  "
	@echo "MINISHELL"
	@echo "  "
	@echo "  "


clean:
	@echo "🧹 ALL FILES HAVE BEEN DELETED 🧹"
	@rm -rf $(OBJ)


fclean: clean
	@echo "🧹 ALL FILES HAVE BEEN DELETED 🧹"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus