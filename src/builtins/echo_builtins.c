#include "../../minishell.h"

void	ft_echo(char *str, int out)
{
    int i = 0;
    while (str[i] != ' ')
        i++;
    i = i + 1;
    while(str[i])
    {   
        ft_putchar_fd(str[i], out);  
        i++;
    }
    ft_putstr_fd("\n", out);
   
}

