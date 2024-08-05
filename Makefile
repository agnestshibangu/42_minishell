# Program name
NAME	=  minishell

# Compiler options
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g

# program files
# SRC		= 	$(PRINTF_OBJS) \

SRC		= 	$(PRINTF_OBJS) \
			mini_libft.c \
			prompt.c \
			main.c \
	
OBJ		= $(SRC:.c=.o)

all : $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

# Compiling minishell
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -g
	@echo "  "  
	@echo " minishell ! "  
	@echo "  "  

clean:
	@echo "🧹 ALL FILES HAVE BEEN DELETED 🧹"
	@rm -rf $(OBJ)


fclean: clean
	@echo "🧹 ALL FILES HAVE BEEN DELETED 🧹"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus