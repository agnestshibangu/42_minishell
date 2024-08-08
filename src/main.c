#include "../minishell.h"

int main(int ac, char **av, char **envp)
//int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_tabenv tabenv;
	char *str;
	char *name;

	name = "allo=4";
	str = "~";

	// init tableau environnement
	init_env_tab(&tabenv, envp);
	// builtin print env
	//print_env(&tabenv);
	// builtin echo
	// echo(str, 1);
	// unset var
	// unset_var(name, &tabenv);
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("\n");
	// pwd
	// ft_pwd();
	// export 
	export_var(name, &tabenv);
	// cd
	// change_directory(str);
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("\n");
	print_env(&tabenv);

	return (0);
}