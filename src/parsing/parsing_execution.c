/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsion <thsion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:49:36 by thsion            #+#    #+#             */
/*   Updated: 2024/08/28 15:42:38 by thsion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_node	*parse_execution(char **start_scan, char *end_input)
{
	t_node		*node;
	t_exec_node	*exec_node;
	char		*startoken;
	char		*endoken;
	int			i;

	node = create_exec_node();                              // initialisation de la node exec
	exec_node = (t_exec_node *)node;                        // cast de la node pour la rendre en exec
	node = parse_redirection(node, start_scan, end_input);
	if (!node)
		return (NULL);
	i = 0;
	while (!peek(start_scan, end_input, "|"))
	{
		if ((getoken(start_scan, end_input, &startoken, &endoken)) == -1)
			break ;
		fill_node(exec_node, startoken, endoken, &i);
		if (i >= 100)
			return (print_error_return("Too much arguments"));
		node = parse_redirection(node, start_scan, end_input);
		if (!node)
			return (NULL);
	}
	return (node);
}

t_node	*create_exec_node(void)
{
	t_exec_node *exec_node;

	exec_node = malloc(sizeof(*exec_node));
	if (!exec_node)
		return (NULL);
	ft_memset(exec_node, 0, (sizeof(*exec_node)));
	exec_node->type = EXEC;
	return ((t_node *)exec_node);
}

void	fill_node(t_exec_node *exec_node, char *startoken, char *endoken,
			int *i)
{
	exec_node->args[*i] = startoken;        // juste rempli la node exec
	exec_node->end_args[*i] = endoken;
	(*i)++;
}

void	put_endline_exec(t_data *data, t_exec_node *exec_node)
{
	int	i;

	i = -1;
	data->nbr_cmd += 1;
	while (exec_node->args[++i])
		*exec_node->end_args[i] = 0;
}
