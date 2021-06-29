/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/17 20:49:03 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/06/29 17:48:35 by mvan-wij      ########   odam.nl         */
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

#include "libft.h"
#include "pipex.h"

/**
 * access:		check file accessibility								// DONE: error prot
 * unlink:		delete file												//
 * pipe:		create pipe from one process to another					// DONE: error prot
 * dup:			duplicate file descriptor								//
 * dup2:		duplicate file descriptor to specific new fd			// DONE: error prot
 * execve:		exec executable (arg1) with args (arg2) and env (arg3)	// DONE: error prot
 * fork:		create child process									// DONE: error prot
 * waitpid:		wait for change state of process
 * wait:		wait for change state of process
 * perror:		create error message for last system function
 * strerror:	also something
 */


// static void	chain_recurse(char **cmds, int fd_in, int fd_out, char **envp)
// {
// 	t_pipefd	pipefd;
//	pid_t		cpid;

// 	if (cmds[2] == NULL)
// 	{
//		cpid = safe_fork();
// 		if (cpid == 0)
// 			exec_cmd_fd_in_out(cmds[0], fd_in, fd_out, envp);
// 		safe_close(fd_out);
//		wait_pid(cpid, NULL, 0);
// 		return ;
// 	}
// 	pipefd = create_pipe();
// 	if (safe_fork() == 0)
// 	{
// 		safe_close(pipefd.read);
// 		exec_cmd_fd_in_out(cmds[0], fd_in, pipefd.write, envp);
// 	}
// 	safe_close(fd_in);
// 	safe_close(pipefd.write);
// 	chain_recurse(&cmds[1], pipefd.read, fd_out, envp);
// }

// static void	chain_recurse_start(char **cmds, char *f, int fd_out, char **envp)
// {
// 	t_pipefd	pipefd;
// 	int			fd_in;

// 	pipefd = create_pipe();
// 	if (safe_fork() == 0)
// 	{
// 		safe_close(pipefd.read);
// 		fd_in = safe_open(f, O_RDONLY, 0);
// 		exec_cmd_fd_in_out(cmds[0], fd_in, pipefd.write, envp);
// 	}
// 	safe_close(pipefd.write);
// 	chain_recurse(&cmds[1], pipefd.read, fd_out, envp);
// }







// static void	chain_itter(char **cmds, int fd_in, int fd_out, char **envp)
// {
// 	t_pipefd	pipefd;
// 	pid_t		cpid;
// 	int			i;

// 	i = 0;
// 	while (cmds[i + 2] != NULL)
// 	{
// 		pipefd = create_pipe();
// 		if (safe_fork() == 0)
// 		{
// 			safe_close(pipefd.read);
// 			exec_cmd_fd_in_out(cmds[i], fd_in, pipefd.write, envp);
// 		}
// 		safe_close(fd_in);
// 		safe_close(pipefd.write);
// 		fd_in = pipefd.read;
// 		i++;
// 	}
// 	cpid = safe_fork();
// 	if (cpid == 0)
// 		exec_cmd_fd_in_out(cmds[i], fd_in, fd_out, envp);
// 	safe_close(fd_in);
// 	safe_close(fd_out);
// 	waitpid(cpid, NULL, 0);
// }

// static void	chain_itter_start(char **cmds, char *f_in, int fd_out, char **envp)
// {
// 	t_pipefd	pipefd;
// 	int			fd_in;

// 	pipefd = create_pipe();
// 	if (safe_fork() == 0)
// 	{
// 		safe_close(pipefd.read);
// 		fd_in = safe_open(f_in, O_RDONLY, 0);
// 		exec_cmd_fd_in_out(cmds[0], fd_in, pipefd.write, envp);
// 	}
// 	safe_close(pipefd.write);
// 	chain_itter(&cmds[1], pipefd.read, fd_out, envp);
// }



static void	chain_itter_last(char *cmd, int fd_in, char *f_out, char **envp)
{
	pid_t	cpid;
	int		fd_out;

	cpid = safe_fork();
	if (cpid == 0)
	{
		fd_out = safe_open(f_out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		exec_cmd_fd_in_out(cmd, fd_in, fd_out, envp);
	}
	safe_close(fd_in);
	waitpid(cpid, NULL, 0);
}

static void	chain_itter(char **cmds, int fd_in, char *f_out, char **envp)
{
	t_pipefd	pipefd;
	pid_t		cpid;
	int			i;
	int			fd_out;

	i = 0;
	while (cmds[i + 2] != NULL)
	{
		pipefd = create_pipe();
		if (safe_fork() == 0)
		{
			safe_close(pipefd.read);
			exec_cmd_fd_in_out(cmds[i], fd_in, pipefd.write, envp);
		}
		safe_close(fd_in);
		safe_close(pipefd.write);
		fd_in = pipefd.read;
		i++;
	}
	chain_itter_last(cmds[i], fd_in, f_out, envp);
}

static void	chain_itter_start(char **cmds, char *f_in, char *f_out, char **envp)
{
	t_pipefd	pipefd;
	int			fd_in;

	pipefd = create_pipe();
	if (safe_fork() == 0)
	{
		safe_close(pipefd.read);
		fd_in = safe_open(f_in, O_RDONLY, 0);
		exec_cmd_fd_in_out(cmds[0], fd_in, pipefd.write, envp);
	}
	safe_close(pipefd.write);
	chain_itter(&cmds[1], pipefd.read, f_out, envp);
}

/**
 * 1. read file1
 * 2. pipe to cmd1
 * 3. keep chaining to next command
 * 4. pipe to file2
 */
int	main(int argc, char **argv, char **envp)
{
	int			fd_out;

	if (argc < 5)
	{
		write(STDERR_FILENO, "pipex: Wrong number of arguments\n", 33);
		exit(EXIT_FAILURE);
	}
	chain_itter_start(&argv[2], argv[1], argv[argc - 1], envp);
}
