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

void general_exec(char *command, t_tabenv *tabenv)
{    
	// first_argument = isolating_first_argument(command);
	printf("%s", command );
	//is_builtin(command, tabenv);
	// run_exec(t_node *exec_node, tabenv);
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


