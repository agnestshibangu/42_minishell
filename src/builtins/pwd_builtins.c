/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <agtshiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:12:14 by thsion            #+#    #+#             */
/*   Updated: 2024/08/11 16:34:36 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int     ft_pwd(void)
{
    char    cwd[256];

    if (getcwd(cwd, sizeof(cwd)) == NULL)
    {
        write(1, "error PWD\n", 10);
        return (0);
    }
    else 
    {
        ft_putstr_fd(cwd, 1);
        return (1);
    }
}

