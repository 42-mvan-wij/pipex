/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/17 20:49:03 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/06/20 11:21:54 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
// access, unlink, close, read, write, pipe, dup, dup2, execve, fork
#include <fcntl.h> // open
#include <stdlib.h> // malloc, free, exit
#include <sys/wait.h> // waitpid, wait
#include <stdio.h> // perror
#include <string.h> // strerror
#include <sys/types.h> // pid_t
#include <errno.h>

#include "../libft/libft.h"
#include "pipex.h"

/**
 * access:		check file accessibility
 * unlink:		delete file
 * pipe:		create pipe from one process to another
 * dup:			duplicate file descriptor
 * dup2:		duplicate file descriptor to specific new fd
 * execve:		exec executable (arg1) with args (arg2) and env (arg3)
 * fork:		create child process
 * waitpid:		wait for change state of process
 * wait:		wait for change state of process
 * perror:		create error message for last system function
 * strerror:	also something
 */
static int	safe_open(const char *filename, int oflag, int mode)
{
	int	fd;

	fd = open(filename, oflag, mode);
	if (fd == -1)
	{
		write(STDERR_FILENO, "pipex: open: ", 13);
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		write(STDERR_FILENO, ": ", 2);
		ft_putstr_fd((char *)filename, STDERR_FILENO);
		write(STDERR_FILENO, "\n", 1);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

static int	safe_fork(void)
{
	pid_t	cpid;

	cpid = fork();
	if (cpid == -1)
	{
		perror("pipex: fork");
		exit(EXIT_FAILURE);
	}
	return (cpid);
}

// static void	chain_recurse(char **cmds, int fd_in, int fd_out, char **envp)
// {
// 	t_pipefd	pipefd;

// 	if (cmds[2] == NULL)
// 	{
// 		if (safe_fork() == 0)
// 			exec_cmd_fd_in_out(cmds[0], fd_in, fd_out, envp);
// 		close(fd_out);
// 		return ;
// 	}
// 	pipefd = create_pipe();
// 	if (safe_fork() == 0)
// 	{
// 		close(pipefd.read);
// 		exec_cmd_fd_in_out(cmds[0], fd_in, pipefd.write, envp);
// 	}
// 	close(fd_in);
// 	close(pipefd.write);
// 	chain_recurse(&cmds[1], pipefd.read, fd_out, envp);
// }

static void	chain_itter(char **cmds, int fd_in, int fd_out, char **envp)
{
	t_pipefd	pipefd;
	int			i;

	i = 0;
	while (cmds[i + 2] != NULL)
	{
		pipefd = create_pipe();
		if (safe_fork() == 0)
		{
			close(pipefd.read);
			exec_cmd_fd_in_out(cmds[i], fd_in, pipefd.write, envp);
		}
		close(fd_in);
		close(pipefd.write);
		fd_in = pipefd.read;
		i++;
	}
	if (safe_fork() == 0)
		exec_cmd_fd_in_out(cmds[i], fd_in, fd_out, envp);
	close(fd_in);
	close(fd_out);
}

/**
 * 1. read file1
 * 2. pipe to cmd1
 * 3. keep chaining to next command
 * 4. pipe to file2
 */
int	main(int argc, char **argv, char **envp)
{
	t_pipefd	pipefd;
	int			fd;
	char		buf[PX_BUF_SIZE];
	int			read_len;

	if (argc < 5)
	{
		write(STDERR_FILENO, "pipex: Wrong number of arguments\n", 33);
		exit(EXIT_FAILURE);
	}
	fd = safe_open(argv[1], O_RDONLY, 0);
	pipefd = create_pipe();
	chain_itter(&argv[2], fd, pipefd.write, envp);
	fd = safe_open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0740);
	read_len = 1;
	while (read_len > 0)
	{
		read_len = read(pipefd.read, buf, PX_BUF_SIZE);
		write(fd, buf, read_len);
	}
}
