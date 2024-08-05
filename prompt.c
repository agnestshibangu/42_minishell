
#include "minishell.h"

int	display_prompt(void)
{
	// char	*ret;
	// int		p_fd[2];

	// if (pipe(p_fd) == -1)
	// 	return (1);
	while (1)
	{
		ft_putstr_fd(">", 0);
		// ret = get_next_line(0);
		// if (ft_strncmp(ret, av[2], ft_strlen(av[2])) == 0
		// 	&& ret[ft_strlen(av[2])] == '\n')
		// {
		// 	free(ret);
		// 	break ;
		// }
		// write(p_fd[1], ret, ft_strlen(ret));
		// free(ret);
	}
	// close(p_fd[1]);
	// dup2(p_fd[0], 0);
	// close(p_fd[0]);
	return (0);
}