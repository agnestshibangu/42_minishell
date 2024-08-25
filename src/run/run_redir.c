/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <agtshiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:59:13 by agtshiba          #+#    #+#             */
/*   Updated: 2024/08/25 18:34:50 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	reopen_stdin_stdout(int fd)
{
	if (fd == 0)
	{
		if (open("/dev/tty", O_RDONLY) < 0)
			ft_error("open stdin failed");
	}
	else if (fd == 1)
	{
		if (open("/dev/tty", O_WRONLY) < 0)
			ft_error("open stdout failed");
	}
}


void    run_heredoc(t_redir_node *redir_node)
{
    char	*ret;
	int		p_fd[2];

	if (pipe(p_fd) == -1)
		return (1);
	while (1)
	{
		ft_putstr_fd(">", 0);
		ret = get_next_line(0);
		if (ft_strncmp(ret, av[2], ft_strlen(av[2])) == 0
			&& ret[ft_strlen(av[2])] == '\n')
		{
			free(ret);
			break ;
		}
		write(p_fd[1], ret, ft_strlen(ret));
		free(ret);
	}
	close(p_fd[1]);
	dup2(p_fd[0], 0);
	close(p_fd[0]);
	return (0);   
}

void    ft_heredoc(t_redir_node *redir_node)
{
    int file; 
    
    char	*ret;
	int		fd[2];

    run_heredoc(redir_node);
    file = open(".here_doc", O_RDONLY, 0777);
    if (file < 0)
        printf("error with heredoc");
    if (dup2(file, 0) < 0)
        printf("error with dup2");
    close(file); 
}

void	run_redir(t_node *tree, t_data *data)
{
	t_redir_node	*redir_node;

	redir_node = (t_redir_node *)tree;
	if (redir_node->r_type == HEREDOC)
	{
		dup2(data->stdin_cpy, STDIN_FILENO);
		ft_heredoc(redir_node);
	}
	else
	{
		if (close(redir_node->fd) < 0)
			ft_error("close stdin/stdout failed");
		if (open(redir_node->file, redir_node->mode, 0777) < 0)
			ft_error(redir_node->file);
	}
	run(redir_node->cmd, data);
	reopen_stdin_stdout(redir_node->fd);
	return ;
}