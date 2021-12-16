/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_args2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/21 15:50:27 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/12/14 13:12:26 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	count_unescaped_quotes(char *str, char quote)
{
	int	count;
	int	i;
	int	escaped;

	i = 0;
	escaped = 0;
	count = 0;
	while (str[i] != '\0')
	{
		escaped = (!escaped && (str[i] == '\\'));
		if (!escaped && str[i] == quote)
			count++;
		i++;
	}
	return (count);
}

char	*remove_unescaped_quotes(char *arg, char quote)
{
	int		i;
	int		escaped;
	int		count;
	char	*new_arg;

	count = count_unescaped_quotes(arg, quote);
	new_arg = malloc((ft_strlen(arg) - count + 1) * sizeof(char));
	if (new_arg == NULL)
		return (NULL);
	i = 0;
	escaped = 0;
	while (*arg != '\0')
	{
		escaped = (!escaped && (*arg == '\\'));
		if (escaped || *arg != quote)
		{
			new_arg[i] = *arg;
			i++;
		}
		arg++;
	}
	new_arg[i] = '\0';
	return (new_arg);
}

static int	count_empty(char **arg_arr, int len)
{
	int	count;

	count = 0;
	while (len > 0)
	{
		len--;
		if (arg_arr[len][0] == '\0')
			count++;
	}
	return (count);
}

char	**remove_empty(char **arg_arr, int len)
{
	int		new_len;
	char	**new_arg_arr;

	new_len = len - count_empty(arg_arr, len);
	new_arg_arr = malloc((new_len + 1) * sizeof(char *));
	if (new_arg_arr == NULL)
		return (NULL);
	len = 0;
	while (len < new_len)
	{
		if ((*arg_arr)[0] != '\0')
		{
			new_arg_arr[len] = *arg_arr;
			len++;
		}
		else
			free(*arg_arr);
		arg_arr++;
	}
	new_arg_arr[len] = NULL;
	return (new_arg_arr);
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
