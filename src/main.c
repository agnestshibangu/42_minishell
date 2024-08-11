/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsion <thsion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:11:36 by thsion            #+#    #+#             */
/*   Updated: 2024/08/11 12:54:48 by thsion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	g_status;
// EXEMPLE DE PROCESSUS D'EXECUTION :
/* void	general_exec(input, data)
{
	if(builtin)
		-----> exec_bulting.c
	if (pipe)
		------ > exec_pipe.c
} */

void 	show_prompt()
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
			echo(command, 1);
		} 
		// free(command);
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
	show_prompt();
	// (5) FREE AND CLEAN
	free_minishell(&tabenv);
	return (0);
}
