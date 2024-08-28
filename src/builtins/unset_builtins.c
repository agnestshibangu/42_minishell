/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsion <thsion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:12:18 by thsion            #+#    #+#             */
/*   Updated: 2024/08/28 15:28:12 by thsion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int unset_var(const char *name, t_data *data)
{
    int len = strlen(name);
    int i = 0;
    int j = 0;

    while (data->env_vars[i] != NULL)
    {
        if (strncmp(data->env_vars[i], name, len) == 0 && data->env_vars[i][len] == '=')
        {
            free(data->env_vars[i]);
            j = i;
            while (data->env_vars[j])
            {
                data->env_vars[j] = data->env_vars[j + 1];
                j++;
            }
            data->env_vars[j] = NULL;
            printf("successfully remove the environ");
        }
        i++;
    }
    printf("failed the remove the variable");
    return (1);
}

