/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <agtshiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:20:57 by agtshiba          #+#    #+#             */
/*   Updated: 2024/08/25 18:30:21 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char 	*isolating_first_argument(char *str)
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
        printf("Memory allocation error\n");
    while (str[i])
	{
		name[y++] = str[i++];
	}
	return (name);
}

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

void    run(t_node *node, t_tabenv *tabenv)
{
    // run_exec_node(node, tabenv);
    // EXEC
    if (node->type == EXEC)
        run_exec_node(node, tabenv);
    // PIPE
    else if (node->type == PIPE)
        run_pipe_node(node, tabenv);
    // REDIR
    // else if (node->type == 4)
    //     run_redirection(node, tabenv);
}

void    dup_right(int *fd)
{
    close(fd[1]); // Close the write end of the pipe in the right process
    dup2(fd[0], 0); // Redirect stdin to the read end of the pipe
    close(fd[0]);
}

void   dup_left(int *fd)
{
    close(fd[0]);
	dup2(fd[1], 1);
	close(fd[1]);    
}