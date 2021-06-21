/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/18 12:57:35 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/06/20 11:24:53 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../libft/libft.h"
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
	{
		if (access(cmd, X_OK) == 0)
			return (cmd);
		return (NULL);
	}
	if (ft_strchr(cmd, '/') != NULL)
	{
		pwd_slash = ft_strjoin(pwd, "/");
		ret = ft_strjoin(pwd_slash, cmd);
		free(pwd_slash);
		if (access(ret, X_OK) == 0)
			return (ret);
		return (NULL);
	}
	return (find_in_path(cmd, paths));
}

static char	**get_cmd_args(char *cmd, char **paths, char *pwd)
{
	char	**args;
	char	*cmd_path;

	args = ft_split(cmd, ' ');
	cmd_path = real_cmd(args[0], paths, pwd);
	if (cmd_path == NULL)
	{
		write(STDERR_FILENO, "pipex: Command not found: ", 26);
		ft_putstr_fd(args[0], STDERR_FILENO);
		write(STDERR_FILENO, "\n", 1);
		exit(EXIT_FAILURE);
	}
	args[0] = cmd_path;
	return (args);
}

void	exec_cmd(char *cmd, char **envp)
{
	char	**args;

	args = get_cmd_args(
			cmd,
			ft_split(get_env_var("PATH", envp), ':'),
			get_env_var("PWD", envp));
	if (execve(args[0], args, envp) == -1)
	{
		perror("pipex: execve");
		exit(EXIT_FAILURE);
	}
}

void	exec_cmd_fd_in_out(char *cmd, int stdin_fd, int stdout_fd, char **envp)
{
	dup2(stdin_fd, STDIN_FILENO);
	dup2(stdout_fd, STDOUT_FILENO);
	exec_cmd(cmd, envp);
}
