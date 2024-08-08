#include "../../minishell.h"

int     ft_pwd(void)
{
    char    cwd[256];

    if (getcwd(cwd, sizeof(cwd)) == NULL)
    {
        write(1, "error PWD\n", 10);
        return (0);
    }
    else 
    {
        ft_putstr_fd(cwd, 1);
        return (1);
    }
}

