/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_variables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <agtshiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:30:02 by agtshiba          #+#    #+#             */
/*   Updated: 2024/08/19 16:06:51 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int ft_update_shell_level(t_tabenv *tabenv)
{
    
    int x = 0;
    size_t len;
    char *name = "SHLVL";
    int y;
    int z;
    int num_to_update;
    char *temp;
    
    x = 0;
    len = ft_strlen(name);

    while (tabenv->env_vars[x] != NULL)
    {
        if (ft_strncmp(tabenv->env_vars[x], name, len) == 0 && tabenv->env_vars[x][len] == '=')
        {   
            y = 0;
            while (tabenv->env_vars[x][y] != '=')
                y++;
            z = y;    
            num_to_update = ft_atoi(&tabenv->env_vars[x][z + 1]) + 1;
            temp = ft_strdup(ft_itoa(num_to_update));
            z = z + 1;
            y = 0;
            while (temp[y])
                tabenv->env_vars[x][z++] = temp[y++];
        }
        x++;
    }
    return 0;
}
