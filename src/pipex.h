/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/18 12:46:10 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/06/20 01:16:02 by mvan-wij      ########   odam.nl         */
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

#endif
