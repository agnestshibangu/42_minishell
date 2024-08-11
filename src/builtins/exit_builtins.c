/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsion <thsion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:12:06 by thsion            #+#    #+#             */
/*   Updated: 2024/08/11 11:12:07 by thsion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void handle_exit(char *input) {
    if (ft_strncmp(input, "exit", 4) == 0) {
        printf("Exiting shell...\n");
        exit(0);  
    }
}