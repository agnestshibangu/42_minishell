/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <agtshiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:49:22 by agtshiba          #+#    #+#             */
/*   Updated: 2024/08/24 12:40:49 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// t_node *create_exec_node(int type, bool is_builtin, const char *command, char **args)
t_node *create_exec_node(int type, bool is_builtin, const char *command)
{
    t_exec_node *node = malloc(sizeof(t_exec_node));

    node->type = type;
    node->is_builtin = is_builtin;

    // Allouer et copier la commande
    node->command = strdup(command);

    // // Compter le nombre d'arguments
    // int args_count = 0;
    // while (args[args_count])
    //     args_count++;

    // // Allouer l'espace pour les arguments
    // node->args = malloc((args_count + 1) * sizeof(char *));

    // Copier les arguments
    // int i = 0;
    // while (i < args_count)
    // {
    //     node->args[i] = strdup(args[i]);
    //     i++;
    // }
    // node->args[args_count] = NULL; // Terminer le tableau avec NULL

    return (t_node *)node;
}

t_node *create_pipe_node(int type, t_node *left, t_node *right)
{
    t_pipe_node *pipe_node = malloc(sizeof(t_pipe_node));

    t_exec_node *left_node = (t_exec_node *)left;
    t_exec_node *right_node = (t_exec_node *)right;
    
    if (type == 3)
        pipe_node->type = type;
   
    
    pipe_node->left_node = (t_node *)left_node; 
    pipe_node->right_node = (t_node *)right_node;
    
    return ((t_node *)pipe_node);
}