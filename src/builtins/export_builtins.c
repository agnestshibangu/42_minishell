/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <agtshiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:12:10 by thsion            #+#    #+#             */
/*   Updated: 2024/08/11 16:34:31 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int ft_export(char *str, t_tabenv *tabenv)
{
    char *name = NULL;
    int i;
    int y;
    int name_len;

    i = 0;
    y = 0;
    name_len = 0;

    // isolating argument
    while (str[i] != ' ')
        i++;
    i = i + 1;
    
  
    while (str[i + name_len])
        name_len++;

    name = (char *)malloc(sizeof(char) * (name_len + 1));
    if (!name)
    {
        printf("Memory allocation error\n");
        return (1);
    }    

    while (str[i])
        name[y++] = str[i++];

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
    return (1);
}


