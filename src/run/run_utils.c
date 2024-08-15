/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <agtshiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:20:57 by agtshiba          #+#    #+#             */
/*   Updated: 2024/08/15 11:20:58 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char 	*isolating_first_argument(char *str)
{
	char *name = NULL;
    int i;
    int y;
    int name_len;

    i = 0;
    y = 0;
    name_len = 0;

    // isolating argument
    while (str[i] != ' ')
        i++;
    i = i + 1;
    
  
    while (str[i + name_len])
        name_len++;

    name = (char *)malloc(sizeof(char) * (name_len + 1));
    if (!name)
        printf("Memory allocation error\n");
    while (str[i])
	{
		name[y++] = str[i++];
	}
	return (name);
}
