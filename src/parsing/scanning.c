/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsion <thsion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:39:14 by thsion            #+#    #+#             */
/*   Updated: 2024/08/19 11:32:54 by thsion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	getoken(char **start_scan, char *end_scan, char **startoken,
	char **endoken)
{
	char	*str;
	int		type;

	str = *start_scan;
	type = 0;
	while (str < end_scan && is_space(*str))
		str++;
	if (str >= end_scan)
		return (-1);
	if (*str == '"' || *str == '\'')
		type = quoted_token(&str, startoken, endoken);
	else
	{
		if (startoken)
			*startoken = str;
		type = get_type(&str, type, end_scan);
		if (endoken)
			*endoken = str;
	}
	while (str < end_scan && is_space(*str))
		str++;
	*start_scan = str;
	return (type);
}

int	quoted_token(char **input, char **startoken, char **endoken)
{
	char	quote;

	quote = **input;
	*startoken = *input;
	(*input)++;
	if (**input == quote)
	{
		(*input)++;
		*endoken = *input;
	}
	else
	{
		*startoken = *input;
		while (**input != quote)
			(*input)++;
		*endoken = *input;
		if (is_quotes(**input))
			(*input)++;
	}
	return (EXEC);
}

int fill_type(char **input, int type, char *end_scan)
{
	if (**input == '|')
	{
		type = PIPE;
		(*input)++;
	}
	else if (**input == '<' || **input == '>')
		type = fill_redir(input, type);
	else
	{
		type = EXEC;
		while (*input < end_scan && !is_space(**input) && !is_symbol(**input)
			&& !is_quotes(**input))
			(*input)++;
	}
	return (type);
}

int	fill_redir(char **input, int type)
{
	if (**input == '<')
	{
		(*input)++;
		if (**input == '<')
		{
			type = HEREDOC;
			(*input)++;
		}
		else
			type = IN_REDIR;
	}
	else if (**input == '>')
	{
		(*input)++;
		if (**input == '>')
		{
			type = APPEND;
			(*input)++;
		}
		else
			type = OUT_REDIR;
	}
	return (type);
}

