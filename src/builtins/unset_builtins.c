/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsion <thsion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:12:18 by thsion            #+#    #+#             */
/*   Updated: 2024/08/11 11:12:19 by thsion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int unset_var(const char *name, t_tabenv *tabenv)
{
    int len = strlen(name);
    int i = 0;
    int j = 0;

    while (tabenv->env_vars[i] != NULL)
    {
        if (strncmp(tabenv->env_vars[i], name, len) == 0 && tabenv->env_vars[i][len] == '=')
        {
            free(tabenv->env_vars[i]);
            j = i;
            while (tabenv->env_vars[j])
            {
                tabenv->env_vars[j] = tabenv->env_vars[j + 1];
                j++;
            }
            tabenv->env_vars[j] = NULL;
            printf("successfully remove the environ");
        }
        i++;
    }
    printf("failed the remove the variable");
    return (1);
}

