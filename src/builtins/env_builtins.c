/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <agtshiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:21:25 by agtshiba          #+#    #+#             */
/*   Updated: 2024/08/15 11:31:14 by agtshiba         ###   ########.fr       */
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

