/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsion <thsion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:56:40 by thsion            #+#    #+#             */
/*   Updated: 2024/08/19 16:14:20 by thsion           ###   ########.fr       */
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

	tmp = input;                                    // creation copie de l'input
	if (!tmp)
		return (NULL);
	tabenv->start_input = tmp;                      // stockage dans data
	end_input = tmp + ft_strlen(tmp);               // pointeur sur la fin de l'input (utile pour token)
	tree = parse_exec(&tmp, end_input, tabenv);     // allez on goooooo
	if (!tree)
	{
		free(input);
		free(tabenv->start_input);                  // gestion erreur si tree vide
		return (NULL);
	}
	tree = put_endline(tree);                       // mise en place des '\0' entre chaque commandes
	return (tree);                                  // return dans le main et ca part en exec
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
	node = create_exec_node();                              //initialisation de la node exec
	exec_node = (t_exec_node *)node;                        // cast de la node pour la rendre en exec
    getoken(start_scan, end_input, &startoken, &endoken);   // on chope les commandes et les aruments
	fill_node(exec_node, startoken, endoken, &i);           // on les met dans la node
	if (i >= 100)                                           // gestion si on depasse la limite !!!!
		return (printf("FUCK"), NULL);                      // (pas ouf le "FUCK") a changer !
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

int	peek(char **start_scan, char *end_input, char *target)
{
	char	*str;

	str = *start_scan;
	while (str < end_input && is_whitespace(*str))
		str++;
	*start_scan = str;
	return (*str && ft_strchr(target, *str));
}
