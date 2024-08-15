/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <agtshiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:11:42 by thsion            #+#    #+#             */
/*   Updated: 2024/08/15 11:30:03 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int init_env_tab(t_tabenv *tabenv, char **envp)
{
    char **copy_of_env;
    int     env_len;

    env_len = 0;
    while (envp[env_len])
        env_len++;
    copy_of_env = malloc((env_len + 1) * sizeof(char *));
    if (!copy_of_env)
        return (1);
    env_len = 0;
    while (envp[env_len])
    {   
        copy_of_env[env_len] = ft_strdup(envp[env_len]);
        env_len++;
    }
    copy_of_env[env_len] = NULL;
    tabenv->env_vars = copy_of_env;
    // free(copy_of_env);
    printf("copy of env done !\n");
    return (0);
}