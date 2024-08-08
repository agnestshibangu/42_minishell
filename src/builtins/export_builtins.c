#include "../../minishell.h"

int export_var(char *name, t_tabenv *tabenv)
{
    int i = 0;
    while (tabenv->env_vars[i] != NULL)
    {
        i++;
    }
    char **new_env_var = malloc(sizeof(char *) * (i + 2));
    if (!new_env_var)
    {
        ft_printf("error");
        return (1);
    }
    new_env_var = strdup(name);
    tabenv->env_vars[i] = new_env_var;

    tabenv->env_vars[i] = name;
    tabenv->env_vars[i + 1] = NULL;
    ft_printf("\nsuccessfully adding variable\n");
    return (1);
}

