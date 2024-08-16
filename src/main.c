/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsion <thsion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:11:36 by thsion            #+#    #+#             */
/*   Updated: 2024/08/15 17:51:39 by thsion           ###   ########.fr       */
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

void 	show_prompt(t_tabenv *tabenv)
{
	char *input;
    t_node  *final_node;

    (void)tabenv;
	while (1)
	{
		signal_handler();
		input = readline("minishell$ ");

		// securite
		if (check_empty_input(input))
		{
            //clearing_input(input, tabenv);
			add_history(input);
            final_node = starting_tree(input, tabenv); // ce truc return l'arbre a executer
            printf("%d\n", final_node->type);
		} 
		// free(command);
	}
}

int main(int ac, char **av, char **envp)
{
	t_tabenv tabenv;

	(void)av;
	if (ac > 1)
		printf("🚫 Minishell doesn't take arguments. Still launching Minishell ... 🚫");
	// (1) INIT ENV AND PARAM
	init_env_tab(&tabenv, envp);
	if (!tabenv.env_vars)
		return (1);
	// command = "blabla";
	// char *name;
	// name = "allo=4";
	// str = "~";

	// (2) BOOL PARSING
	// (3) INPUT CLEAN
	// -------------------- 
	// (4) SET UP SIGNALS (4) SHOW PROMPT
	show_prompt(&tabenv);
	// (6) FREE AND CLEAN
	free_minishell(&tabenv);
	return (0);
}
