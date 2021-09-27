/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/18 12:46:10 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/07/03 15:41:48 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

typedef struct s_pipefd {
	int	read;
	int	write;
}	t_pipefd;

t_pipefd	create_pipe(void);
char		*get_env_var(char *var, char **envp);
void		exec_cmd(char **args, char **envp);
void		exec_cmd_fd_in_out(char **args, int in_fd, int out_fd, char **envp);
char		*ft_str_filter(char *str, char *remove_set);
char		*remove_unescaped_quotes(char *arg, char quote);
char		**remove_empty(char **arg_arr, int len);
void		*free_arg_arr(char **arg_arr);
char		**correct_args(char *cmd);
int			safe_open(const char *filename, int oflag, int mode);
int			safe_fork(void);
void		safe_close(int fd);
char		**get_cmd_args(char *cmd);

#endif
