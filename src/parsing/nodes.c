/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsion <thsion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:49:36 by thsion            #+#    #+#             */
/*   Updated: 2024/08/19 16:04:15 by thsion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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

t_node	*create_pipe_node(t_node *left, t_node *right)
{
	t_pipe_node	*pipe_node;

	pipe_node = malloc(sizeof(*pipe_node));
	if (!pipe_node)
		return (NULL);
	ft_memset(pipe_node, 0, sizeof(*pipe_node));
	pipe_node->type = PIPE;
	pipe_node->left = left;
	pipe_node->right = right;
	if (!pipe_node->right)
	{
		free(pipe_node->left);
		free(pipe_node);
		return (NULL);
	}
	return ((t_node *)pipe_node);
}

t_node	*create_redir_node(int token_type, t_node *cmd, char *start_file,
			char *end_file)
{
	t_redir_node	*redir_node;

	redir_node = malloc(sizeof(*redir_node));
	if (!redir_node)
		return (NULL);
	ft_memset(redir_node, 0, sizeof(*redir_node));
	redir_node->type = REDIR;
	redir_node->r_type = token_type;
	if (token_type == HEREDOC)
		g_status = -42;
	redir_node->cmd = cmd;
	redir_node->file = start_file;
	redir_node->end_file = end_file;
	init_fd_and_mode(token_type, redir_node);
	if (cmd->type == REDIR)
		return (multiple_redir(cmd, redir_node));
	return ((t_node *)redir_node);
}
