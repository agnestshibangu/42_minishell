
#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1 
# endif

// PUTSTR_FD
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
int	display_prompt(void);

#endif