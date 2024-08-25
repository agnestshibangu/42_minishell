/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <agtshiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:11:36 by thsion            #+#    #+#             */
/*   Updated: 2024/08/25 11:02:31 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// EXEMPLE DE PROCESSUS D'EXECUTION :
/* void	general_exec(input, data)
{
	if(builtin)
		-----> exec_bulting.c
	if (pipe)
		------ > exec_pipe.c
} */



// void general_exec(char *command, t_tabenv *tabenv)
// {    
// 	first_argument = isolating_first_argument(command);
// 	t_exec_node exec_node;
	
// 	init_exec_node(&exec_node, command);
// 	if (run_builtin(command, tabenv))
// 		printf("je suis un builtin");
	
// 	if (!run_builtin(command, tabenv))
// 	 	run_exec(command, tabenv);
// }

// void 	show_prompt(t_tabenv *tabenv)
// {
// 	char *command;

// 	while (1)
// 	{
// 		signal_handler();
// 		command = readline("minishell$ ");

// 		// securite
// 		if (command == NULL)
// 		{
// 			printf("exit\n");
// 			break;
// 		}
// 		if (command)
// 		{
// 			add_history(command);
// 			general_exec(command, tabenv);
// 		}
		
// 		free(command);
// 	}
// }

int main(int ac, char **av, char **envp)
{
	t_tabenv tabenv;
	
 	
	// (void)envp;
	(void)ac;
	(void)av;

	init_env_tab(&tabenv, envp);

 	// char *argz[] = {"arg1", "arg2", "arg3", NULL};
 	// char *argz2[] = {"arg1", "arg2", "arg3", NULL};

	// -----------------------------------------
	// EXEC COMMANDS AND BUILTINS
	// init_env_tab(&tabenv, envp);
    // t_node *node = create_exec_node(2, false, "ls", argz);
	// run_exec_node(node, &tabenv);
	
	// -----------------------------------------
	// EXEC PIPE AND MULTI PIPES
	// node DROITE -> gauche et DROITE -> droite                  
	// t_node *left_down_level = create_exec_node(2, false, "rev");
	// t_node *right_down_level = create_exec_node(2, false, "");
	// node GAUCHE 
	// t_node *left = create_exec_node(2, false, "cat file1.txt");
	// node a DROITE  
	// t_node *sub_pipe_node = create_pipe_node(3, left_down_level, right_down_level);
	// pipe principal avec left et right qui est un pipe aussi
	// t_node *pipe_node = create_pipe_node(3, left, sub_pipe_node);
	
	// run_exec_node(left, &tabenv);
	// run_exec_node(right, &tabenv);
	
	//run_pipe_node(pipe_node, &tabenv);

	// -----------------------------------------
	// REDIRECTIONS


	// -----------------------------------------
	
	// command = "blabla";
	// char *name;
	// name = "allo=4";
	// str = "~";

	// (1) BOOL PARSING
	// (2) INPUT CLEANvoid general_exec(char *command, t_tabenv *tabenv)
	// -------------------- 
	// (3) INIT ENV AND PARAM
	// init_env_tab(&tabenv, envp);
	// init_exec_node(&exec_node, av, ac);
	// (3) SET UP SIGNALS (4) SHOW PROMPT
	// show_prompt(&tabenv);
	// (5) FREE AND CLEAN
	// free_minishell(&tabenv);
	return (0);
}
