/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <agtshiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:12:53 by thsion            #+#    #+#             */
/*   Updated: 2024/08/20 15:21:18 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <fcntl.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1 
# endif

extern int	g_status;

typedef struct s_tabenv
{
	char **env_vars;
}              t_tabenv;

// typedef struct s_exec_node
// {
// 	int		type;
//     char    *command;
// }	t_exec_node;


typedef struct s_exec_node
{
	int		type;
	bool	is_builtin;
	char	*command;
	char	**args;
	// char	*end_args[100];
}				t_exec_node;

// init.c

// int		init_exec_node(t_exec_node *exec_node, char **av, int ac);
int init_env_tab(t_tabenv *tabenv, char **envp);
int copy_env_tab(t_tabenv *tabenv, char **envp);
int		init_exec_node(t_exec_node *exec_node, char *command);

// signal.c
void	signal_handler(void);
void	new_routine(int signal);
void	heredoc_signal(void);
void	heredoc_signal_handler(int signal);

// free.c
int		free_minishell(t_tabenv *tabenv); // free the minishell at the very end

// run builtins
int run_builtin(char *command, t_tabenv *tabenv);
// echo
void	ft_echo(char *str, int out);
// cd_builtins.c
int		ft_cd(char *str);
// pwd_builtins.c
int		ft_pwd(void);
// export_builtins.c
int		ft_export(char *name, t_tabenv *tabenv);
// shell level
// int     update_shell_level(char *command, t_tabenv *tabenv);
int     ft_update_shell_level(t_tabenv *tabenv);
// unset_builtins.c

// env_builtins.c



char 	*isolating_first_argument(char *str);

// exit_builtins.c
// void	ft_exit(char *input);
void 	ft_exit();

char	*ft_env(t_tabenv *tabenv);
// unset
int ft_unset(const char *str, t_tabenv *tabenv);
// run exec
void    run_exec(char *command, t_tabenv *tabenv);
// change shell level
int ft_update_shell_level(t_tabenv *tabenv);


// void    run_exec(t_exec_node *exec_node, t_tabenv *tabenv)
void    fill_struct(char *command, t_exec_node *exec_node);

/*				PIPEX & GNL				*/
// pipex bonus
void	exec(char *cmd, char **env);
void	child(char *cmd, int *p_fd, char **env);
void	parent(int *p_fd);
void	my_free_tab(char **tab);
void	no_here_doc(char **av);
void	finish_pipe(char **av, int ac, char **env);
void	handle_pipex(char **av, int ac, t_tabenv *tabenv);
char	*get_every_path(char **env, char *cmd);
char	*find_path_variable_function(char **env);
int		find_path_var(char *name);
int		open_file(char *file, int in_or_out);
int		here_doc(char **av);
int		create_a_pipe(char *cmd, char **env);
				//void	no_here_doc(char **av, int i);
				//int	exec(char *cmd, char **env);

// gnl
char	*get_next_line(int fd);
char	*manage_storage(char *storage, char *buffer);
char	*make_line(int fd, char *buffer, char *storage);
void	free_backup(char *backup);
char	*my_extract(char *line);
void	free_storage(char *storage);

// free
int     free_minishell(t_tabenv *tabenv); // free the minishell at the very end

// signals
void signal_handler(void);
void new_routine(int signal);
void	heredoc_signal(void);
void	heredoc_signal_handler(int signal);

int		ft_atoi(char *str);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_tolower(int c);
int		ft_toupper(int c);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);

int		ft_atoi(char *str);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_tolower(int c);
int		ft_toupper(int c);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);



#endif 