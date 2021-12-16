/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils1.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/18 12:44:06 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/12/16 18:44:27 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int	safe_open(const char *filename, int oflag, int mode)
{
	int	fd;

	fd = open(filename, oflag, mode);
	if (fd == -1)
	{
		write(STDERR_FILENO, "pipex: ", 7);
		perror(filename);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

int	safe_fork(void)
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

void	safe_close(int fd)
{
	if (close(fd) == -1)
	{
		perror("pipex: close");
		exit(EXIT_FAILURE);
	}
}
