/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/18 12:44:06 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/06/20 00:16:15 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../libft/libft.h"
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
	const char	*var_equals_sign = ft_strjoin(var, "=");
	const int	len = ft_strlen(var_equals_sign);
	int			i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(var_equals_sign, envp[i], len) == 0)
			return (envp[i] + len);
		i++;
	}
	return (NULL);
}
