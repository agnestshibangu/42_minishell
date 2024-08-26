/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <agtshiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:59:13 by agtshiba          #+#    #+#             */
/*   Updated: 2024/08/26 21:28:54 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// void	reopen_stdin_stdout(int fd)
// {
// 	if (fd == 0)
// 	{
// 		if (open("/dev/tty", O_RDONLY) < 0)
// 			printf("open stdin failed");
// 	}
// 	else if (fd == 1)
// 	{
// 		if (open("/dev/tty", O_WRONLY) < 0)
// 			printf("open stdout failed");
// 	}
// }

// file c'est le delimiter
// void    run_heredoc(t_redir_node *redir_node)
void    run_heredoc(t_redir_node *redir_node, int p_fd[2])
{
    char	*ret;
	// int		p_fd[2];

	if (pipe(p_fd) == -1)
	{
		printf("error pipe");
		// return (1);
	}	
	while (1)
	{
		ft_putstr_fd(">", 0);
		ret = get_next_line(0);
		if (ft_strncmp(ret, redir_node->file, ft_strlen(redir_node->file)) == 0
			&& ret[ft_strlen(redir_node->file)] == '\n')
		{
			free(ret);
			break ;
		}
		write(p_fd[1], ret, ft_strlen(ret));
		free(ret);
	}
	close(p_fd[1]);
    dup_right(p_fd); 
	// dup_right(p_fd);
	// return (0);   
}

void    ft_heredoc(t_redir_node *redir_node)
{
    int p_fd[2];  // Créer un pipe pour connecter le heredoc et la commande suivante

    if (pipe(p_fd) == -1)
    {
        printf("error pipe");
        exit(EXIT_FAILURE);  // Assurez-vous de gérer les erreurs correctement
    }

    run_heredoc(redir_node, p_fd);

    // Connecter le côté de lecture du pipe à stdin
    if (dup2(p_fd[0], 0) < 0)
        printf("error with dup2");
    close(p_fd[0]);  // Fermer le côté de lecture du pipe après l'avoir redirigé
}

// void    ft_heredoc(t_redir_node *redir_node)
// {
//     int file; 
// 	// int	fd[2];
// 	//char	*ret;

//     run_heredoc(redir_node);
//     file = open(".here_doc", O_RDONLY, 0777);
//     if (file < 0)
//         printf("error with heredoc");
//     if (dup2(file, 0) < 0)
//         printf("error with dup2");
//     close(file); 
// }

void	run_redir_node(t_node *node, t_tabenv *tabenv)
{
	t_redir_node	*redir_node;

	redir_node = (t_redir_node *)node;
	if (redir_node->redir_type == HEREDOC)
	{
		// il faudra mettre une copie
		ft_heredoc(redir_node);
	}
	else
	{
		if (close(redir_node->fd) < 0)
			printf("close stdin/stdout failed");
		if (open(redir_node->file, redir_node->mode, 0777) < 0)
			printf("open has failed miserably");
	}
	run(redir_node->cmd, tabenv);
	// reopen_stdin_stdout(redir_node->file);
	return ;
}