/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <agtshiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:21:39 by agtshiba          #+#    #+#             */
/*   Updated: 2024/08/15 11:21:40 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int ft_unset(const char *str, t_tabenv *tabenv)
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

    int len = strlen(name);
    int j = 0;
    int x = 0;
    while (tabenv->env_vars[x] != NULL)
    {
        if (ft_strncmp(tabenv->env_vars[x], name, len) == 0 && tabenv->env_vars[x][len] == '=')
        {
            free(tabenv->env_vars[x]);
            j = x;
            while (tabenv->env_vars[j])
            {
                tabenv->env_vars[j] = tabenv->env_vars[j + 1];
                j++;
            }
            tabenv->env_vars[j] = NULL;
        }
        x++;
    }
    free(name);
    printf("failed the remove the variable\n");
    return (1);
}

