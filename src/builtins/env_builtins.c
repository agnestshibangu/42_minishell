/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <agtshiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:12:02 by thsion            #+#    #+#             */
/*   Updated: 2024/08/11 16:34:23 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

