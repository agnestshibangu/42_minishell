/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsion <thsion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:56:40 by thsion            #+#    #+#             */
/*   Updated: 2024/08/16 11:26:53 by thsion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

bool	check_empty_input(char *input)
{
	int i;
	int j;

	i = 0;
	if (input[i] == '\0')
	{
		return (false);
	}
	while (input[i] == ' ' || input[i] == '\t' || input[i] == '\n'
		|| input[i] == '\v' || input[i] == '\f' || input[i] == '\r')
		i++;
	j = ft_strlen(input);
	if (i == j)
		return (false);
	return (true);
}

t_node	*starting_tree(char *input, t_tabenv *tabenv)
{
	t_node	*tree;
	char	*end_input;
	char	*tmp;

	tmp = input;
	if (!tmp)
		return (NULL);
	tabenv->start_input = tmp;
	end_input = tmp + ft_strlen(tmp);
    printf("%s\n", tmp);
	tree = parse_exec(&tmp, end_input, tabenv);
	if (!tree)
	{
		free(input);
		free(tabenv->start_input);
		return (NULL);
	}
	tree = put_endline(tree);
	return (tree);
}

t_node	*parse_exec(char **start_scan, char *end_input, t_tabenv *tabenv)
{
	t_node		*node;
	t_exec_node	*exec_node;
	char		*startoken;
	char		*endoken;
	int			i;

    (void)tabenv;
	i = 0;
	node = create_exec_node();
	exec_node = (t_exec_node *)node;
	getoken(start_scan, end_input, &startoken, &endoken);
	fill_node(exec_node, startoken, endoken, &i);
	if (i >= 100)
		return (printf("FUCK"), NULL);
	return (node);
}

t_node	*put_endline(t_node *tree)
{
	t_exec_node		*exec_node;
    int             i;

    i = 0;
	if (tree->type == EXEC)
	{
		exec_node = (t_exec_node *)tree;
		while (exec_node->args[i])
	    {
		    *exec_node->end_args[i] = 0;
		    i++;
	    }
	}
	return (tree);
}

void	fill_node(t_exec_node *exec_node, char *startoken, char *endoken,
			int *i)
{
	exec_node->args[*i] = startoken;
	exec_node->end_args[*i] = endoken;
	(*i)++;
}