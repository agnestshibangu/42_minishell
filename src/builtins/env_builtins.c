/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsion <thsion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:12:02 by thsion            #+#    #+#             */
/*   Updated: 2024/08/28 15:27:17 by thsion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*print_env(t_data *data)
{
	int	i;

	i = 0;
	while (data->env_vars[i])
	{
		ft_putstr_fd(data->env_vars[i], 1);
        ft_putchar_fd('\n', 1);
		i++;
	}
	return (NULL);
}

