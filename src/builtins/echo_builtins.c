#include "../../minishell.h"

void	echo(char *str, int out)
{
    ft_putstr_fd("je suis la fonction echo : ", out);
    ft_putstr_fd(str, out); 
    ft_putstr_fd("\n", out);
}

