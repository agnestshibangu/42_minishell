/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <agtshiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:11:36 by thsion            #+#    #+#             */
/*   Updated: 2024/08/15 11:30:31 by agtshiba         ###   ########.fr       */
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


void general_exec(char *command, t_tabenv *tabenv)
{    
	// first_argument = isolating_first_argument(command);
	if (!run_builtin(command, tabenv))
		run_exec(command, tabenv);
}

void 	show_prompt(t_tabenv *tabenv)
{
	char *command;

	while (1)
	{
		signal_handler();
		command = readline("minishell$ ");

		// securite
		if (command == NULL)
		{
			printf("exit\n");
			break;
		}
		if (command)
		{
			add_history(command);
			general_exec(command, tabenv);
		}
		free(command);
	}
}

int main(int ac, char **av, char **envp)
{
	t_tabenv tabenv;
	
	(void)ac;
	(void)av;

	// command = "blabla";
	// char *name;
	// name = "allo=4";
	// str = "~";

	// (1) BOOL PARSING
	// (2) INPUT CLEAN
	// -------------------- 
	// (3) INIT ENV AND PARAM
	init_env_tab(&tabenv, envp);
	// (3) SET UP SIGNALS (4) SHOW PROMPT
	show_prompt(&tabenv);
	// (5) FREE AND CLEAN
	free_minishell(&tabenv);
	return (0);
}
