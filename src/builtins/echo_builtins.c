/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsion <thsion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:11:58 by thsion            #+#    #+#             */
/*   Updated: 2024/08/11 11:11:59 by thsion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	echo(char *str, int out)
{
    ft_putstr_fd("je suis la fonction echo : ", out);
    ft_putstr_fd(str, out); 
    ft_putstr_fd("\n", out);
}

