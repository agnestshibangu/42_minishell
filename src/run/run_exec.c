/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <agtshiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:21:07 by agtshiba          #+#    #+#             */
/*   Updated: 2024/08/24 12:38:19 by agtshiba         ###   ########.fr       */
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
        my_free_tab(argv);
}

void run_command(char **path, char **argv, t_tabenv *tabenv)
{
    *path = get_every_path(tabenv->env_vars, argv[0]);
    if (!*path) 
        my_free_tab(argv);
}

void	run_exec(char *cmd, t_tabenv *tabenv)
{
	char	*path;
	char	**argv;

    path = NULL; 

    argv = ft_split(cmd, ' ');
    if (!argv || !argv[0])
        exit(EXIT_FAILURE);
    if (strchr(argv[0], '/') != NULL) // runner un  
        run_path(argv, &path);
    else
        run_command(&path, argv, tabenv);
    // printf("Executing: %s\n", path);
    if (execve(path, argv, tabenv->env_vars) == -1) {
        perror("execve failed");
        if (path != argv[0]) {
            free(path); 
        }
        my_free_tab(argv);
    }
}

// void	run_exec(char *cmd, t_tabenv *tabenv)
// {
// 	char	*path;
// 	char	**argv;
//     pid_t	pid = fork();

//     path = NULL;

//     if (pid == -1) {
//         perror("error: failed to fork");
//         return;
//     } 
//     else if (pid == 0) {  // Child process
//         argv = ft_split(cmd, ' ');
//         if (!argv || !argv[0])
//             exit(EXIT_FAILURE);
//         if (strchr(argv[0], '/') != NULL) // runner un  
//             run_path(argv, &path);
//         else
//             run_command(&path, argv, tabenv);
//         printf("Executing: %s\n", path);
//         if (execve(path, argv, tabenv->env_vars) == -1) {
//             perror("execve failed");
//             if (path != argv[0]) {
//                 free(path); 
//             }
//             my_free_tab(argv);
//         }
//     } 
//     else {
//         int status;
//         waitpid(pid, &status, 0);  // Attend que l'enfant se termine
//     }
// }


// ---------------- en attendant les nodes ---------------------






// void	run_exec(t_node *tree, t_data *data)
// {
// 	t_exec_node	*exec_node;
// 	char		*path;

// 	exec_node = (t_exec_node *)tree;
// 	if (exec_node->is_builtin == true)
// 	{
// 		run_builtin(exec_node->args, data);
// 	}
// 	else
// 	{
// 		path = get_path(exec_node->args[0], data);
// 		if (execve(exec_node->args[0], exec_node->args, data->env_cpy) == -1)
// 		{
// 			if (execve(path, exec_node->args,
// 					data->env_cpy) == -1)
// 			{
// 				free(path);
// 				ft_error(exec_node->args[0]);
// 				exi  // // Libérer la mémoire
        // free(node->command);
        // for (int i = 0; node->args[i] != NULL; i++)
        // {
        //     free(node->args[i]);
        // }
        // free(node->args);
        // free(node);t(1);
// 			}
// 		}
// 	}
// }




// void    fill_struct(char *command, t_node *t_exec_node)
// {
//     exec_node->command = command;

// }

void    run_exec_node(t_node *node, t_tabenv *tabenv)
{
    // char *every_path;

    t_exec_node *exec_node = (t_exec_node *)node;

    if (exec_node->is_builtin == true)
    {
        // printf("THIS IS A BUILTIN : %s\n", exec_node->command);
        run_builtin(exec_node->command, tabenv);
    }
    else if (exec_node->is_builtin == false)
    {
        // printf("THIS IS NOT A BUILTIN : %s\n", exec_node->command);
        run_exec(exec_node->command, tabenv);
        //every_path = get_every_path(tabenv->env_vars, exec_node->command);
    }
}