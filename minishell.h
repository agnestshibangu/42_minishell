#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
// # include <readline/readline.h>
// # include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <fcntl.h>
# include <stdbool.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct s_tabenv
{
    char **env_vars;
}              t_tabenv;


// init
int init_env_tab(t_tabenv *tabenv, char **envp);

// --- builtins ---

// echo
void	echo(char *str, int out);
// cd
int change_directory(char *str);
// pwd
int     ft_pwd(void);
// export
int export_var(char *name, t_tabenv *tabenv);
// unset 

// env
// exit

char	*print_env(t_tabenv *tabenv);

// unset
int unset_var(const char *name, t_tabenv *tabenv);



#endif 