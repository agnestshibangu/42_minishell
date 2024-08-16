/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsion <thsion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:12:53 by thsion            #+#    #+#             */
/*   Updated: 2024/08/15 17:42:23 by thsion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
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

typedef enum e_type
{
	EXEC,
	PIPE,
	REDIR,
}			t_type;

typedef struct s_node
{
	int	type;
}				t_node;

typedef struct s_exec_node
{
	int		type;
	bool	is_builtin;
	char	*args[100];
	char	*end_args[100];
}				t_exec_node;

typedef struct s_tabenv
{
	char **env_vars;
	char *start_input;
}              t_tabenv;


// init.c
int		init_env_tab(t_tabenv *tabenv, char **envp);

// signal.c
void	signal_handler(void);
void	new_routine(int signal);
void	heredoc_signal(void);
void	heredoc_signal_handler(int signal);

// free.c
int		free_minishell(t_tabenv *tabenv); // free the minishell at the very end
void	free_tab(char **tab);

/*              PARSING             */

// parsing.c
bool	check_empty_input(char *input);
t_node	*starting_tree(char *input, t_tabenv *tabenv);
t_node	*parse_exec(char **start_scan, char *end_input, t_tabenv *tabenv);
t_node	*put_endline(t_node *tree);
void	fill_node(t_exec_node *exec_node, char *startoken, char *endoken,
		int *i);

// scanning.c
int		getoken(char **start_scan, char *end_input, char **startoken,
		char **endoken);
bool	is_whitespace(char c);

// nodes.c
t_node	*create_exec_node(void);

/*				BUILTINS				*/

// echo_builtins.c
void	echo(char *str, int out);

// cd_builtins.c
int		change_directory(char *str);

// pwd_builtins.c
int		ft_pwd(void);

// export_builtins.c
int		export_var(char *name, t_tabenv *tabenv);

// unset_builtins.c


// env_builtins.c
char	*print_env(t_tabenv *tabenv);

// exit_builtins.c
void	handle_exit(char *input);


// unset_builtins.c
int		unset_var(const char *name, t_tabenv *tabenv);

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

/*				LIBFT				*/

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