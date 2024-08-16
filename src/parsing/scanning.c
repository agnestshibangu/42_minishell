/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsion <thsion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:39:14 by thsion            #+#    #+#             */
/*   Updated: 2024/08/15 17:51:20 by thsion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	getoken(char **start_scan, char *end_input, char **startoken,
	char **endoken)
{
	char	*str;
	int		type;

	str = *start_scan;
	type = 0;
	while (str < end_input && is_whitespace(*str))
		str++;
	if (str >= end_input)
		return (-1);
	if (startoken)
		*startoken = str;
	type = EXEC;
	while (str < end_input && is_whitespace(*str))
		str++;
	if (endoken)
		*endoken = str;
	*start_scan = str;
	return (type);
}

bool	is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (true);
	return (false);
}

