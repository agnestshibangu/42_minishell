/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <agtshiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:21:22 by agtshiba          #+#    #+#             */
/*   Updated: 2024/08/15 11:21:23 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_echo(char *str, int out)
{
    int i = 0;
    while (str[i] != ' ')
        i++;
    i = i + 1;
    while(str[i])
    {   
        ft_putchar_fd(str[i], out);  
        i++;
    }
    ft_putstr_fd("\n", out);
   
}

