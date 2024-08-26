/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <agtshiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:49:22 by agtshiba          #+#    #+#             */
/*   Updated: 2024/08/26 21:02:02 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// t_node *create_exec_node(int type, bool is_builtin, const char *command, char **args)
t_node *create_exec_node(t_type type, bool is_builtin, const char *command)
{
    t_exec_node *node = malloc(sizeof(t_exec_node));

    node->type = type;
    node->is_builtin = is_builtin;
    node->command = strdup(command);

    return (t_node *)node;
}

// t_node *create_pipe_node(int type, t_node *left, t_node *right)
t_node *create_pipe_node(t_type type, t_node *left, t_node *right)
{
    t_pipe_node *pipe_node = malloc(sizeof(t_pipe_node));

    t_exec_node *left_node = (t_exec_node *)left;
    t_exec_node *right_node = (t_exec_node *)right;
     
    pipe_node->type = type;
   
    pipe_node->left_node = (t_node *)left_node; 
    pipe_node->right_node = (t_node *)right_node;
    
    return ((t_node *)pipe_node);
}

t_node *create_redir_node(t_type type, char *stop_word, int redir_type, t_node *node_cmd)
// t_node *create_redir_node(t_type type, char *redir_type, char *stop_word, t_node *node_cmd)
{
    t_redir_node *redir_node = malloc(sizeof(t_redir_node));

    t_exec_node *cmd_node = (t_exec_node *)node_cmd;
    
    redir_node->cmd = (t_node *)cmd_node;
    redir_node->type = type;
    redir_node->redir_type = redir_type;
    redir_node->file = stop_word;
  
    
    return ((t_node *)redir_node);
}