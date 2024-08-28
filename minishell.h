/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsion <thsion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:12:53 by thsion            #+#    #+#             */
/*   Updated: 2024/08/28 15:40:14 by thsion           ###   ########.fr       */
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

extern int	g_status;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1 
# endif

typedef enum e_type
{
	EXEC,
	PIPE,
	REDIR,
}			t_type;

typedef enum e_redir
{
	HEREDOC,
	APPEND,
	IN_REDIR,
	OUT_REDIR,
}
			t_redir;

typedef struct s_node
{
	int	type;
}				t_node;

typedef struct s_exec_node
{
	int		type;
	char	*args[100];
	char	*end_args[100];
}				t_exec_node;

typedef struct s_pipe_node
{
	int		type;
	t_node	*left;
	t_node	*right;
}				t_pipe_node;

typedef struct s_redir_node
{
	int		type;
	int		redir_type;
	int		mode;
	int		fd;
	char	*file;
	char	*end_file;
	t_node	*cmd;
}				t_redir_node;

typedef struct s_data
{
	int		nbr_cmd;
	char	**env_vars;
	char	*start_input;
}				t_data;


// init.c
int		init_env_tab(t_data *data, char **envp);

// signal.c
void	signal_handler(void);
void	new_routine(int signal);
void	routine_child(int signal);
//void	heredoc_signal(void);
//void	heredoc_signal_handler(int signal);

// free.c
int		free_minishell(t_data *data); // free the minishell at the very end
void	free_tab(char **tab);

/*--------------------------------------------PARSING--------------------------------------------*/

// parsing.c
t_node	*starting_tree(char *input, t_data *data);
t_node	*put_endline(t_node *tree, t_data *data);
bool	check_empty_input(char *input);

// check_&_clean.c
char	*check_fix_input(char *input, t_data *data);
char	*clean(char *new_input, char *input, t_data *data);
char	*new_arg(char *new_input, bool *open_tok, char quote);
char	*quotes_overload(char **input, char *new_input, t_data *data);
char	*input_fixed(char *new_input, char **input);

// scanning.c
int		getoken(char **start_scan, char *end_input, char **startoken,
		char **endoken);
int		quoted_token(char **input, char **startoken, char **endoken);
int		fill_type(char **input, int type, char *end_input);
int		peek(char **start_scan, char *end_input, char *target);

// parsing_execution.c
t_node	*parse_execution(char **start_scan, char *end_input);
t_node	*create_exec_node(void);
void	fill_node(t_exec_node *exec_node, char *startoken, char *endoken,
		int *i);
void	put_endline_exec(t_data *data, t_exec_node *exec_node);

// parsing_utils_1.c
bool	is_quotes(char c);
bool	is_symbol(char c);
bool	is_space(char c);
bool	is_all(char c);
t_node	*print_error_return(char *error);

// parsing_utils_2.c
bool	open_quotes(char *input);
bool	empty_pipe(char *input);
bool	is_quoted_arg(char *input, char *quote_type);
void	skip_space(char **input);
char	*join_char(char *s1, char c);

// parsing_utils_3.c
void	quotes_checker(int *simple_quote, int *double_quotes, char *input, int i);
bool	wtfami(int count_quotes);

// parsing_redirections.c
t_node	*parse_redirection(t_node *node, char **start_scan, char *end_input);
t_node	*create_redir_node(int token_type, t_node *cmd, char *start_file,
		char *end_file);
t_node	*multiple_redir(t_node *cmd, t_redir_node *prev_redir);
void	init_redirection(int token_type, t_redir_node	*redir_node);
int		fill_redirection(char **str, int type);

// parsing_pipe.c
t_node	*check_4_pipes(char **start_scan, char *end_input, t_data *data);
t_node	*create_pipe_node(t_node *left, t_node *right);
int		check_next_arg(char *start_scan, char *end_input);


/*-------------------------------------------BUILTINS-------------------------------------------*/

// echo_builtins.c
void	echo(char *str, int out);

// cd_builtins.c
int		change_directory(char *str);

// pwd_builtins.c
int		ft_pwd(void);

// export_builtins.c
int		export_var(char *name, t_data *data);

// unset_builtins.c


// env_builtins.c
char	*print_env(t_data *data);

// exit_builtins.c
void	handle_exit(char *input);


// unset_builtins.c
int		unset_var(const char *name, t_data *data);

/*------------------------------------------PIPEX & GNL------------------------------------------*/
// pipex bonus
void	exec(char *cmd, char **env);
void	child(char *cmd, int *p_fd, char **env);
void	parent(int *p_fd);
void	my_free_tab(char **tab);
void	no_here_doc(char **av);
void	finish_pipe(char **av, int ac, char **env);
void	handle_pipex(char **av, int ac, t_data *data);
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

/*------------------------------------------LIBFT------------------------------------------*/

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