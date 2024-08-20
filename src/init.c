/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <agtshiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:11:42 by thsion            #+#    #+#             */
/*   Updated: 2024/08/20 15:22:30 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int copy_env_tab(t_tabenv *tabenv, char **envp)
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
    ft_update_shell_level(tabenv);  
    return (0); 
}

int init_env_tab(t_tabenv *tabenv, char **envp)
{
    copy_env_tab(tabenv, envp);
    printf("copy of env done !\n");
    return (0);
}

// char 	*isolating_first_argument(char *str)
// {
// 	char *name = NULL;
//     int i;
//     int y;
//     int name_len;
//     char *begin_pointer;
//     char *end_pointer;

//     i = 0;
//     y = 0;

    
//     // isolating argument
//     while (str[i] == ' ')
//         i++;
//     begin_pointer = str[i + 1];
    
//     y = i;
//     while (str[y] != ' ')
//         y++;
//     end_pointer = str[y];
//     name_len = y - i;
    
//     name = (char *)malloc(sizeof(char) * (name_len + 1));
//     if (!name)
//         printf("Memory allocation error\n");
//     y = i;    
//     i = 0;
//     while (str[y])
// 	{
// 		name[i++] = str[y++];
// 	}
//     printf("%s", name);
// 	return (name);
// }



int init_exec_node(t_exec_node *exec_node, char *command)
{
    // char **node_arguments_copy;
    int     i;
    int     y;
    // int     number_of_arguments;
    
    i = 1;
    y = 0;
    printf("je suis dans init exec node");
    isolating_first_argument(command);
    
    printf("\n");
    //node_arguments_copy = malloc((ac) * sizeof(char *));
      
    //if (!node_arguments_copy)
    //     return (1);
    exec_node->command = ft_strdup(command);
    printf("Command: %s\n", exec_node->command);
    // i = 0;
    // y = 2;
    // while (y < ac)
    // {
    //     printf("args: %s\n", av[y]);
    //     node_arguments_copy[i] = ft_strdup(av[y]);
    //     i++;
    //     y++;
    // }
    // node_arguments_copy[i] = NULL;
    // exec_node->args = node_arguments_copy;
    // i = 0;
    // printf("Command: %s\n", exec_node->command);
    // while (exec_node->args[i])
    // {
    //     printf("%s\n", exec_node->args[i]);
    //     i++;
    // }

    return (0);
}


// int init_exec_node(t_exec_node *exec_node, char **av, int ac)
// {
//     char **node_arguments_copy;
//     int     i;
//     int     y;
//     // int     number_of_arguments;
    
//     i = 1;
//     y = 0;
//     printf("je suis dans init exec node");
//     node_arguments_copy = malloc((ac) * sizeof(char *));
      
//     if (!node_arguments_copy)
//          return (1);
//     exec_node->command = ft_strdup(av[1]);
//     printf("Command: %s\n", exec_node->command);
//     i = 0;
//     y = 2;
//     while (y < ac)
//     {
//         printf("args: %s\n", av[y]);
//         node_arguments_copy[i] = ft_strdup(av[y]);
//         i++;
//         y++;
//     }
//     node_arguments_copy[i] = NULL;
//     exec_node->args = node_arguments_copy;
//     i = 0;
//     printf("Command: %s\n", exec_node->command);
//     while (exec_node->args[i])
//     {
//         printf("%s\n", exec_node->args[i]);
//         i++;
//     }

//     return (0);
// }