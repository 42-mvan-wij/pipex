/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/18 12:46:10 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/06/21 16:11:05 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>

# ifndef PX_BUF_SIZE
#  define PX_BUF_SIZE 8
# endif

typedef struct s_pipefd {
	int	read;
	int	write;
}	t_pipefd;

t_pipefd	create_pipe(void);
char		*get_env_var(char *var, char **envp);
void		exec_cmd(char *cmd, char **envp);
void		exec_cmd_fd_in_out(char *cmd, int stdin_fd, int stdout_fd,
				char **envp);
char		*ft_str_filter(char *str, char *remove_set);
char		*remove_unescaped_quotes(char *arg, char quote);
char		**remove_empty(char **arg_arr, int len);
void		free_arg_arr(char **arg_arr);
char		**correct_args(char *cmd);

#endif
