/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/18 12:44:06 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/06/29 17:09:44 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "libft.h"
#include "pipex.h"

static int	safe_open(const char *filename, int oflag, int mode)
{
	int	fd;

	fd = open(filename, oflag, mode);
	if (fd == -1)
	{
		write(STDERR_FILENO, "pipex: open: ", 13);
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		write(STDERR_FILENO, ": ", 2);
		ft_putendl_fd((char *)filename, STDERR_FILENO);
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

void	safe_close(int fd)
{
	if (close(fd) == -1)
	{
		perror("pipex: close");
		exit(EXIT_FAILURE);
	}
}

t_pipefd	create_pipe(void)
{
	t_pipefd	res;
	int			pipefd[2];

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	res.read = pipefd[0];
	res.write = pipefd[1];
	return (res);
}

char	*get_env_var(char *var, char *envp[])
{
	const int	len = ft_strlen(var) + 1;
	char		*var_equals_sign;
	int			i;

	var_equals_sign = ft_strjoin(var, "=");
	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(var_equals_sign, envp[i], len) == 0)
		{
			free(var_equals_sign);
			return (envp[i] + len);
		}
		i++;
	}
	free(var_equals_sign);
	return (NULL);
}
