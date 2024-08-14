#include "../../minishell.h"

int run_builtin(char *command, t_tabenv *tabenv)
{
    if (!ft_strncmp(command, "echo", 4) && (command[4] == ' ' || command[4] == '\0'))
    {
        ft_echo(command, 1);
        return (1); 
    }
    if (!ft_strncmp(command, "env", 3) && (command[3] == ' ' || command[3] == '\0'))
    {
        ft_env(tabenv);
        return (1); 
    }
    if (!ft_strncmp(command, "exit", 4) && (command[4] == ' ' || command[4] == '\0'))
    {
        ft_exit();
        return (1); 
    }
    if (!ft_strncmp(command, "export", 6) && (command[6] == ' ' || command[6] == '\0'))
    {
        ft_export(command, tabenv);
        return (1);
    }
    if (!ft_strncmp(command, "pwd", 3) && (command[3] == ' ' || command[3] == '\0'))
    {
        ft_pwd();
        return (1); 
    }
    if (!ft_strncmp(command, "unset", 5) && (command[5] == ' ' || command[5] == '\0'))
    {
        ft_unset(command, tabenv);
        return (1);
    }
    return (0);
}

