/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <agtshiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:11:47 by thsion            #+#    #+#             */
/*   Updated: 2024/08/15 11:29:57 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int     free_minishell(t_tabenv *tabenv)
{   
    int	nbr_of_lines;
    int i;
	
	nbr_of_lines = 0;
	if (tabenv == NULL)
		return (1);
	if (tabenv->env_vars != NULL)
	{
        while (tabenv->env_vars[nbr_of_lines])
            nbr_of_lines++;
        i = 0;
		while (i < nbr_of_lines)
		{
			free(tabenv->env_vars[i]);
			tabenv->env_vars[i] = NULL;
			i++;
		}
		free(tabenv->env_vars);
	}
    printf("everything has been freed !");
    return (0);
}