#include "../minishell.h"


void 	show_prompt(char *command)
{
	while (1)
	{
		command = readline("minishell$ ");
	}
}



int main(int ac, char **av, char **envp)
{
	t_tabenv tabenv;
	
	(void)ac;
	(void)av;
	char *command;
	command = "blabla";
	// char *name;

	// name = "allo=4";
	// str = "~";

	// (1) BOOL PARSING
	// (2) INPUT CLEAN
	// (3) INIT ENV AND PARAM
	init_env_tab(&tabenv, envp);
	// (3) SET UP SIGNALS
	// (4) SHOW PROMPT
	show_prompt(command);
	// (5) FREE AND CLEAN

	return (0);
}
