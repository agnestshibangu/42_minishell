/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <agtshiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:21:07 by agtshiba          #+#    #+#             */
/*   Updated: 2024/08/15 18:09:37 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void run_path(char **argv, char **path)
{
    // Check if the command is a full path and is executable
    if (access(argv[0], F_OK | X_OK) == 0)
    {
        *path = argv[0];  // If the command is a valid path, use it directly
    } 
    else 
    {
        printf("Invalid path provided: %s\n", argv[0]);
        my_free_tab(argv);
        exit(EXIT_FAILURE);  // Exit the child process
    }
}

void run_command(char **path, char **argv, t_tabenv *tabenv)
{
    *path = get_every_path(tabenv->env_vars, argv[0]);
    if (!*path) 
    {
        printf("command not found\n");
        my_free_tab(argv);
        exit(EXIT_FAILURE);
    }
}

void	run_exec(char *cmd, t_tabenv *tabenv)
{
	char	*path;
	char	**argv;
    pid_t	pid = fork();

    path = NULL;

    if (pid == -1) {
        perror("error: failed to fork");
        return;
    } 
    else if (pid == 0) {  // Child process
        argv = ft_split(cmd, ' ');
        if (!argv || !argv[0])
            exit(EXIT_FAILURE);
        if (strchr(argv[0], '/') != NULL) // runner un  
            run_path(argv, &path);
        else
            run_command(&path, argv, tabenv);
        printf("Executing: %s\n", path);
        if (execve(path, argv, tabenv->env_vars) == -1) {
            perror("execve failed");
            if (path != argv[0]) {
                free(path); 
            }
            my_free_tab(argv);
            exit(EXIT_FAILURE); 
        }
    } 
    else {
        int status;
        waitpid(pid, &status, 0);  // Attend que l'enfant se termine
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