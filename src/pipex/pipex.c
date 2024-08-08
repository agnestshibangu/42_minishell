
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../../minishell.h"

void	exec(char *cmd, char **env)
{
	char	*path;
	char	**argv;

	argv = ft_split(cmd, ' ');
	path = get_every_path(env, argv[0]);
	if (execve(path, argv, env) == -1)
	{
		exit(0);
	}
}

// writing phase, on close R end of pipe, dup file W as EXIT    W == EXIT
void	child(char *cmd, int *p_fd, char **env)
{
	close(p_fd[0]);
	dup2(p_fd[1], 1);
	close(p_fd[1]);
	exec(cmd, env);
}

// writing phase, on close W end of pipe, dup file R as ENTRY   R == ENTRY
void	parent(int *p_fd)
{
	close(p_fd[1]);
	dup2(p_fd[0], 0);
	close(p_fd[0]);
}

int	create_a_pipe(char *cmd, char **env)
{
	pid_t	pid;
	int		p_fd[2];

	if (pipe(p_fd) == -1)
		return (0);
	pid = fork();
	if (pid == 0)
		child(cmd, p_fd, env);
	else
		parent(p_fd);
	return (1);
}

int	here_doc(char **av)
{
	char	*ret;
	int		p_fd[2];

	if (pipe(p_fd) == -1)
		return (1);
	while (1)
	{
		ft_putstr_fd(">", 0);
		ret = get_next_line(0);
		if (ft_strncmp(ret, av[2], ft_strlen(av[2])) == 0
			&& ret[ft_strlen(av[2])] == '\n')
		{
			free(ret);
			break ;
		}
		write(p_fd[1], ret, ft_strlen(ret));
		free(ret);
	}
	close(p_fd[1]);
	dup2(p_fd[0], 0);
	close(p_fd[0]);
	return (0);
}

void	my_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	find_path_var(char *name)
{
	char	*needle;
	int		needle_len;

	needle = "PATH=";
	needle_len = ft_strlen(needle);
	if (ft_strncmp(name, needle, needle_len) == 0)
		return (1);
	else
		return (0);
}

char	*find_path_variable_function(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (find_path_var(env[i]))
			return (env[i]);
		i++;
	}
	return (NULL);
}

char	*get_every_path(char **env, char *cmd)
{
	char	**allpath;
	char	*path_part;
	char	*exec;
	int		i;

	allpath = ft_split(find_path_variable_function(env), ':');
	i = 0;
	while (allpath[i])
	{
		path_part = ft_strjoin(allpath[i], "/");
		exec = ft_strjoin(path_part, cmd);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
			return (exec);
		free(exec);
		i++;
	}
	my_free_tab(allpath);
	return (NULL);
}

int	open_file(char *file, int in_or_out)
{
	int	ret;

	if (in_or_out == 0)
		ret = open(file, O_RDONLY, 0777);
	if (in_or_out == 1)
		ret = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (ret == -1)
		exit(0);
	return (ret);
}

// int	main(int ac, char **av, char **env)
// {
// 	pid_t	pid;
// 	int		p_fd[2];

// 	if (parsing(ac, av) == -1)
// 		return (1);
// 	find_path_variable_function(env);
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
// 		child(av, p_fd, env);
// 	else
// 		parent(av, p_fd, env);
// 	return (0);
// }
