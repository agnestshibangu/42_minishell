/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <agtshiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:11:58 by thsion            #+#    #+#             */
/*   Updated: 2024/08/11 16:23:57 by agtshiba         ###   ########.fr       */
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

