#include "../../minishell.h"

char	*ft_env(t_tabenv *tabenv)
{
	int	i;

	i = 0;
	while (tabenv->env_vars[i])
	{
		ft_putstr_fd(tabenv->env_vars[i], 1);
        ft_putchar_fd('\n', 1);
		i++;
	}
	return (NULL);
}

