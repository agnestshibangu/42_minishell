/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsion <thsion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:12:10 by thsion            #+#    #+#             */
/*   Updated: 2024/08/11 11:12:11 by thsion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        printf("error");
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
    printf("successfully adding variable\n");
    return (1);
}

