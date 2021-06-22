/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_args.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/21 15:50:27 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/06/22 16:27:29 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "pipex.h"

static char	**create_arg_array(char *cmd)
{
	int		i;

	if (cmd == NULL)
		return (NULL);
	i = 0;
	while (*cmd != '\0')
	{
		if (ft_isspace(*cmd))
			i++;
		cmd++;
	}
	return (ft_calloc(i + 1, sizeof(char *)));
}

static void	set_in_quote(int *in_quote, char c, int escaped)
{
	if (escaped || (c != '\'' && c != '\"'))
		return ;
	if (*in_quote == 0)
		*in_quote = c;
	else if (*in_quote == c)
		*in_quote = 0;
}

static char	*fix_arg(char *arg)
{
	int		i;
	char	*new_arg;
	char	*new_arg2;
	char	quote;
	int		escaped;

	i = 0;
	while (ft_isspace(arg[i]))
		i++;
	new_arg = &arg[i];
	quote = '\0';
	escaped = 0;
	while (arg[i] != '\0' && quote == '\0')
	{
		escaped = !escaped && (arg[i] == '\\');
		if (!escaped && (arg[i] == '\'' || arg[i] == '"'))
			quote = arg[i];
		i++;
	}
	if (quote != '\0')
		new_arg = remove_unescaped_quotes(new_arg, quote);
	new_arg2 = ft_str_filter(new_arg, "\\");
	if (quote != '\0' && new_arg != NULL)
		free(new_arg);
	return (new_arg2);
}

static char	**fix_arg_arr(char **arg_arr)
{
	int		i;
	char	**new_arg_arr;

	i = 0;
	while (arg_arr[i + 1] != NULL)
	{
		arg_arr[i + 1][0] = '\0';
		(arg_arr[i + 1])++;
		arg_arr[i] = fix_arg(arg_arr[i]);
		if (arg_arr[i] == NULL)
			return (free_arg_arr(arg_arr));
		i++;
	}
	arg_arr[i] = fix_arg(arg_arr[i]);
	if (arg_arr[i] == NULL)
		return (free_arg_arr(arg_arr));
	new_arg_arr = remove_empty(arg_arr, i + 1);
	free(arg_arr);
	return (new_arg_arr);
}

char	**correct_args(char *cmd)
{
	int		i;
	int		in_quote;
	int		escaped;
	char	**arg_arr;
	int		arg_i;

	in_quote = 0;
	escaped = 0;
	arg_arr = create_arg_array(cmd);
	arg_arr[0] = cmd;
	arg_i = 1;
	i = 0;
	while (cmd[i] != '\0')
	{
		if (ft_isspace(cmd[i]) && !in_quote && !escaped)
		{
			arg_arr[arg_i] = &cmd[i];
			arg_i++;
		}
		set_in_quote(&in_quote, cmd[i], escaped);
		escaped = !escaped && (cmd[i] == '\\');
		i++;
	}
	return (fix_arg_arr(arg_arr));
}
