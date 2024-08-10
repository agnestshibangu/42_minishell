#include "../minishell.h"


void	new_routine(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();// implementer systeme pour avoir une nouvelle ligne vide
	}
}
 
void	signal_handler(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_RESTART;
	sa.sa_handler = new_routine;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
	signal(SIGQUIT, SIG_IGN);
}

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
