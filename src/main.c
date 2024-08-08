#include "../minishell.h"

void	finish_pipe(char **av, int ac, char **env)
{
	int		fd_out;

	fd_out = open_file(av[ac - 1], 1);
	dup2(fd_out, 1);
	close(fd_out);
	exec(av[ac - 2], env);
}

void	no_here_doc(char **av, int i)
{
	int	fd_in;

	fd_in = open_file(av[1], 0);
	dup2(fd_in, 0);
	close(fd_in);
	i = 2;
}

int	main(int ac, char **av, char **envp)
{
	int		i;
	char	*cmd;

	t_tabenv tabenv;

	init_env_tab(&tabenv, envp);
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		here_doc(av);
		i = 3;
	}
	else
	{
		i = 2;
		no_here_doc(av, i);
	}
	while (i < ac - 2)
	{
		cmd = av[i];
		create_a_pipe(cmd, envp);
		i++;
	}
	finish_pipe(av, ac, envp);
	return (0);
}



// int main(int ac, char **av, char **envp)
// {
// 	t_tabenv tabenv;

// 	pid_t	pid;
// 	int		p_fd[2];

// 	init_env_tab(&tabenv, envp);
// 	find_path_variable_function(envp);
// 	if (ac != 5)
// 	{	
// 		ft_printf("too many or too few arguments");
// 		return (0);
// 	}
// 	if (pipe(p_fd) == -1)
// 		return (0);
// 	pid = fork();
// 	if (pid == -1)
// 		return (0);
// 	else if (pid == 0)
// 		child(av, p_fd, envp);
// 	else
// 		parent(av, p_fd, envp);
// 	return (0);

// 	// (void)ac;
// 	// (void)av;
// 	// t_tabenv tabenv;
// 	// char *str;
// 	// char *name;

// 	// name = "allo=4";
// 	// str = "~";

// 	// // init tableau environnement
// 	// init_env_tab(&tabenv, envp);
// 	// // builtin print env
// 	// //print_env(&tabenv);
// 	// // builtin echo
// 	// // echo(str, 1);
// 	// // unset var
// 	// // unset_var(name, &tabenv);
// 	// // pwd
// 	// // ft_pwd();
// 	// // export 
// 	// // export_var(name, &tabenv);
// 	// // cd
// 	// // change_directory(str);
// 	// return (0);
// }