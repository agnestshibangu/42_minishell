/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <agtshiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:21:07 by agtshiba          #+#    #+#             */
/*   Updated: 2024/08/15 11:21:08 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	run_exec(char *cmd,  t_tabenv *tabenv)
{
	char	*path;
	char	**argv;
    pid_t pid = fork();
    
    if (pid == -1) {
        printf("error : failed to fork");
    }

     else if (pid == 0) {
        argv = ft_split(cmd, ' ');
        if (!argv || !argv[0])
            printf("issue with argv");
        path = get_every_path(tabenv->env_vars, argv[0]);
        if (!path) {
            printf("path not found");
            my_free_tab(argv);
        }
        if (execve(path, argv, tabenv->env_vars) == -1) {
            printf("execve failed");
            free(path);        // a mettre dans un free general
            my_free_tab(argv);  // a mettre dans un free general
        }
    }
    else
    {
        // process parent
        int status;
        waitpid(pid, &status, 0);  // attend que le child se termine et yallah le parent prompt continue
    }
}

// ---------------- en attendant les nodes ---------------------



// void    fill_struct(char *command, t_node *t_exec_node)
// {
//     exec_node->command = command;

// }

// void    run_exec(t_node *t_exec_node, t_tabenv *tabenv)
// {
//     char *every_path;


//     if (exec_node->is_builtin == true)
//         run_builtin(exec_node->command, tabenv->env_vars);
//     else
//     {
//         exec(exec_node->command, tabenv->env_vars);
//         //every_path = get_every_path(tabenv->env_vars, exec_node->command);
//     }
// }