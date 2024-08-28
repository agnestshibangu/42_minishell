/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <agtshiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:59:13 by agtshiba          #+#    #+#             */
/*   Updated: 2024/08/28 15:03:49 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"


void	reopen_stdin_stdout(int fd)
{
	if (fd == 0)
	{
		if (open("/dev/tty", O_RDONLY) < 0)
			printf("open stdin failed");
	}
	else if (fd == 1)
	{
		if (open("/dev/tty", O_WRONLY) < 0)
			printf("open stdout failed");
	}
}

int handle_close(int fd)
{
	close(fd);
	fd = open(".here_doc", O_RDONLY, 0777);
	return (fd);
}

int run_heredoc(t_redir_node *redir_node)
{
	char	*line;
	int		file;

	file = open(".here_doc", O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (file < 0)
	{
		printf("error can't read file");
		return -1;
	}
	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			printf("minishell: warning: here-document delimited by end-of-file (wanted %s)\n", redir_node->file);
			break;
		}
		if (ft_strncmp(line, redir_node->file, ft_strlen(redir_node->file)) == 0 && line[ft_strlen(redir_node->file)] == '\0')
		{
			close(file);
			
		}
		ft_putstr_fd(line, file);
		ft_putchar_fd('\n', file);
		free(line);
	}
	return handle_close(file);
}

void ft_heredoc(t_redir_node *redir_node)
{
	int file;

	file = run_heredoc(redir_node);
	if (file < 0)
	{
		printf("error heredoc");
		return;
	}
	// // Rediriger l'entrée standard vers le fichier de heredoc
	// if (dup2(file, STDIN_FILENO) < 0)
	// {
	// 	printf("error dup2");
	// 	close(file);
	// 	return;
	// }
	// close(file);
}

void run_redir_node(t_node *node, t_tabenv *tabenv)
{
	t_redir_node *redir_node;

	redir_node = (t_redir_node *)node;
	if (redir_node->redir_type == HEREDOC)
	{
		ft_heredoc(redir_node);
	}
	run(redir_node->cmd, tabenv);
	reopen_stdin_stdout(redir_node->fd);
}