/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <agtshiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:12:14 by thsion            #+#    #+#             */
/*   Updated: 2024/08/11 16:40:16 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void is_builtin(char *command, t_tabenv *tabenv)
{
    if (!ft_strncmp(command, "echo", 4))
    {
        ft_echo(command, 1);
    }
    if (!ft_strncmp(command, "env", 3))
    {
        ft_env(tabenv);
    }
    if (!ft_strncmp(command, "exit", 4))
    {
        ft_exit();
    }
    if (!ft_strncmp(command, "export", 6))
    {
        ft_export(command, tabenv);
    }
    if (!ft_strncmp(command, "pwd", 3))
    {
        ft_pwd();
    }
    if (!ft_strncmp(command, "unset", 5))
    {
        ft_unset(command, tabenv);
    }

}