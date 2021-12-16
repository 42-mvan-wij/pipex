/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/17 20:49:03 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/12/16 18:54:29 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
// access, unlink, close, read, write, pipe, dup, dup2, execve, fork
#include <fcntl.h> // open
#include <stdlib.h> // malloc, free, exit

#include "libft.h"
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

static void	chain_last(char *cmd, int fd_in, char *f_out, char **envp)
{
	int		fd_out;
	char	**prepared_cmd;

	prepared_cmd = ft_split(cmd, ' ');
	if (safe_fork() == 0)
	{
		fd_out = safe_open(f_out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		exec_cmd_fd_in_out(prepared_cmd, fd_in, fd_out, envp);
	}
	safe_close(fd_in);
	free_arg_arr(prepared_cmd);
}

static void	chain(char **cmds, int fd_in, char *f_out, char **envp)
{
	t_pipefd	pipefd;
	int			i;
	char		**prepared_cmd;

	i = 0;
	while (cmds[i + 2] != NULL)
	{
		pipefd = create_pipe();
		prepared_cmd = ft_split(cmds[i], ' ');
		if (safe_fork() == 0)
		{
			safe_close(pipefd.read);
			exec_cmd_fd_in_out(prepared_cmd, fd_in, pipefd.write, envp);
		}
		safe_close(fd_in);
		safe_close(pipefd.write);
		free_arg_arr(prepared_cmd);
		fd_in = pipefd.read;
		i++;
	}
	chain_last(cmds[i], fd_in, f_out, envp);
}

static void	chain_start(char **cmds, char *f_in, char *f_out, char **envp)
{
	t_pipefd	pipefd;
	int			fd_in;
	char		**prepared_cmd;

	pipefd = create_pipe();
	prepared_cmd = ft_split(cmds[0], ' ');
	if (safe_fork() == 0)
	{
		safe_close(pipefd.read);
		fd_in = safe_open(f_in, O_RDONLY, 0);
		exec_cmd_fd_in_out(prepared_cmd, fd_in, pipefd.write, envp);
	}
	safe_close(pipefd.write);
	free_arg_arr(prepared_cmd);
	chain(&cmds[1], pipefd.read, f_out, envp);
}

static char	**dup_arr(char **arr, int len)
{
	char	**duped_arr;

	duped_arr = malloc((len + 1) * sizeof(char *));
	if (duped_arr == NULL)
	{
		write(STDERR_FILENO, "Failed to dupe array\n", 20);
		exit(EXIT_FAILURE);
	}
	duped_arr[len] = NULL;
	while (len > 0)
	{
		len--;
		duped_arr[len] = ft_strdup(arr[len]);
		if (duped_arr[len] == NULL)
		{
			write(STDERR_FILENO, "Failed to dupe array\n", 20);
			exit(EXIT_FAILURE);
		}
	}
	return (duped_arr);
}

/**
 * 1. read file1
 * 2. pipe to cmd1
 * 3. keep chaining to next command
 * 4. pipe to file2
 */
int	main(int argc, char **argv, char **envp)
{
	char	**argv_dup;
	int		i;

	if (argc < 5 || (!PIPEX_BONUS && argc > 5))
	{
		write(STDERR_FILENO, "pipex: Wrong number of arguments\n", 33);
		exit(EXIT_FAILURE);
	}
	argv_dup = dup_arr(&argv[1], argc - 1);
	chain_start(&argv_dup[1], argv_dup[0], argv_dup[argc - 2], envp);
	i = argc - 3;
	while (i > 0)
	{
		i--;
		wait(NULL);
	}
	while (argc > 1)
	{
		argc--;
		free(argv_dup[argc - 1]);
	}
	free(argv_dup);
	return (EXIT_SUCCESS);
}
