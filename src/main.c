#include "../minishell.h"




// int	main(int ac, char **av, char **envp)
// {
// 	t_tabenv tabenv;
// 	// (void)ac;
// 	// (void)av;

// 	if (!init_env_tab(&tabenv, envp))
// 	{
// 		printf("oui\n");
// 		fflush(stdout);
// 		handle_pipex(av, ac, &tabenv);
// 	}
// 	free_minishell(&tabenv);
// 	return (0);
// }


void handle_exit(char *input) {
    if (strcmp(input, "exit") == 0) {
        printf("Exiting shell...\n");
        exit(0);  
    }
}


int main(int ac, char **av, char **envp)
{
	t_tabenv tabenv;

	// pid_t	pid;
	// int		p_fd[2];

	init_env_tab(&tabenv, envp);
	//find_path_variable_function(envp);
	
	(void)ac;
	//(void)av;
	// char *str;
	// char *name;

	// name = "allo=4";
	// str = "~";

	// init tableau environnement
	init_env_tab(&tabenv, envp);
	// builtin print env
	//print_env(&tabenv);
	// builtin echo
	// echo(str, 1);
	// unset var
	// unset_var(name, &tabenv);
	// pwd
	// ft_pwd();
	// export 
	// export_var(name, &tabenv);
	// cd
	// change_directory(str);
	handle_exit(av[1]);
	return (0);
}