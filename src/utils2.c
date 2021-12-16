/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 17:11:46 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/12/16 18:49:53 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "pipex.h"

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

void	*free_arg_arr(char **arg_arr)
{
	int	i;

	i = 0;
	while (arg_arr[i] != NULL)
	{
		free(arg_arr[i]);
		i++;
	}
	free(arg_arr);
	return (NULL);
}
