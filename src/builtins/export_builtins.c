#include "../../minishell.h"

// replace ("") puis newline puis display 

int export_var(char *name, t_tabenv *tabenv)
{
    int i = 0;
    while (tabenv->env_vars[i] != NULL)
        i++;
    char **new_env_vars = malloc(sizeof(char *) * (i + 2));
    if (!new_env_vars)
    {
        ft_printf("error");
        return (1);
    }
    i = 0;
    while (tabenv->env_vars[i])
    {
        new_env_vars[i] = tabenv->env_vars[i];
        i++;
    }
    new_env_vars[i] = strdup(name);
    new_env_vars[i + 1] = NULL;
    tabenv->env_vars = new_env_vars;
    ft_printf("successfully adding variable\n");
    return (1);
}

