/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/18 12:57:35 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/07/03 15:42:06 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "pipex.h"

static char	*find_in_path(char *cmd, char **paths)
{
	char	*slash_cmd;
	char	*cmd_path;
	int		i;

	if (paths == NULL)
		return (NULL);
	slash_cmd = ft_strjoin("/", cmd);
	i = 0;
	while (paths[i] != NULL)
	{
		cmd_path = ft_strjoin(paths[i], slash_cmd);
		if (access(cmd_path, X_OK) == 0)
		{
			free(slash_cmd);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	free(slash_cmd);
	return (NULL);
}

static char	*real_cmd(char *cmd, char **paths, char *pwd)
{
	char	*pwd_slash;
	char	*ret;

	if (cmd[0] == '/')
		return (cmd);
	if (ft_strchr(cmd, '/') != NULL)
	{
		pwd_slash = ft_strjoin(pwd, "/");
		ret = ft_strjoin(pwd_slash, cmd);
		free(pwd_slash);
		return (ret);
	}
	return (find_in_path(cmd, paths));
}

char	**get_cmd_args(char *cmd)
{
	char	**args;

	args = correct_args(cmd);
	if (args == NULL)
	{
		write(STDERR_FILENO, "Cannot parse command: ", 29);
		ft_putendl_fd(cmd, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (args);
}

void	exec_cmd(char **args, char **envp)
{
	char	*cmd_path;

	cmd_path = real_cmd(args[0],
			ft_split(get_env_var("PATH", envp), ':'), get_env_var("PWD", envp));
	if (cmd_path == NULL)
	{
		write(STDERR_FILENO, "Command not found: ", 26);
		ft_putendl_fd(args[0], STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (access(cmd_path, X_OK) == -1)
	{
		perror(cmd_path);
		exit(EXIT_FAILURE);
	}
	if (execve(cmd_path, args, envp) == -1)
	{
		perror("pipex: execve");
		exit(EXIT_FAILURE);
	}
}

void	exec_cmd_fd_in_out(char **args, int in_fd, int out_fd, char **envp)
{
	if (dup2(in_fd, STDIN_FILENO) == -1)
	{
		perror("pipex: dup2");
		exit(EXIT_FAILURE);
	}
	if (dup2(out_fd, STDOUT_FILENO) == -1)
	{
		perror("pipex: dup2");
		exit(EXIT_FAILURE);
	}
	exec_cmd(args, envp);
}
