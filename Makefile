NAME = minishell
DIR_SRC = src/
DIR_OBJ = obj/
CC = cc 
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -lreadline
RM = rm -f

SRCS =  $(wildcard $(DIR_SRC)*.c) \
		$(wildcard $(DIR_SRC)/parsing/*.c) \
		$(wildcard $(DIR_SRC)/exec/*.c) \
		$(wildcard $(DIR_SRC)/libft/*.c) \
		$(wildcard $(DIR_SRC)/builtins/*.c) \
		$(wildcard $(DIR_SRC)/pipex/*.c) \

OBJS = $(SRCS:$(DIR_SRC)%.c=$(DIR_OBJ)%.o)

all: $(NAME)

$(DIR_OBJ)%.o: $(DIR_SRC)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)
	@echo "  "
	@echo "  "
	@echo "MINISHELL"
	@echo "  "
	@echo "  "

clean:
	@echo "🧹 ALL FILES HAVE BEEN DELETED 🧹"
	rm -rf $(DIR_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all