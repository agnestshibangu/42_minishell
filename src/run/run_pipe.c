/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <agtshiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:24:49 by agtshiba          #+#    #+#             */
/*   Updated: 2024/08/24 15:50:52 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"


int	ft_fork(void)
{
	int	pid;

	pid = fork();
	if (pid == -1)
    {
        printf("error on fork");
        exit(EXIT_FAILURE);
    }

	return (pid);
}

void    run_node_left(t_pipe_node *pipe_node, int *fd, t_tabenv *tabenv)
{
    t_exec_node *exec_node_left = (t_exec_node *)pipe_node->left_node;
    
    close(fd[0]); // Close the read end of the pipe in the left process
    dup2(fd[1], STDOUT_FILENO); // Redirect stdout to the write end of the pipe
    close(fd[1]); // e
 
    run((t_node *)exec_node_left, tabenv);
}

void    run_node_right(t_pipe_node *pipe_node, int *fd, t_tabenv *tabenv)
{
    t_exec_node *exec_node_right = (t_exec_node *)pipe_node->right_node;
    
    close(fd[1]); // Close the write end of the pipe in the right process
    dup2(fd[0], STDIN_FILENO); // Redirect stdin to the read end of the pipe
    close(fd[0]);
    
    run((t_node *)exec_node_right, tabenv);
}

int	wait_for_process(pid_t pid1)
{
	int	status;
	int	return_status;

	return_status = 0;
	waitpid(pid1, &status, 0);
	if (WIFEXITED(status))
		return_status = WEXITSTATUS(status);
	return (return_status);
}

void    run(t_node *node, t_tabenv *tabenv)
{
    // run_exec_node(node, tabenv);
    if (node->type == 2)
        run_exec_node(node, tabenv);
    else if (node->type == 3)
        run_pipe_node(node, tabenv);
}

void    run_pipe_node(t_node *node, t_tabenv *tabenv)
{
    t_pipe_node *pipe_node;
    int     fd[2];
    pid_t   pid1;
    pid_t   pid2;
    
    
    pipe_node = (t_pipe_node *)node;
    if (pipe(fd) == -1)
    {
        printf("error");
        exit(EXIT_FAILURE);
    }
    // NODE CHILD 1   
    pid1 = ft_fork();
    if (pid1 == 0)
    {
        run_node_left(pipe_node, fd, tabenv);
    }
    // if there is heredoc
    
    // NODE CHILD 2
    pid2 = ft_fork();
    if (pid2 == 0)
        run_node_right(pipe_node, fd, tabenv);
    close(fd[0]);
    close(fd[1]);    
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
}


