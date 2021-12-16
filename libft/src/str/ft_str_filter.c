/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str_filter.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/22 00:38:16 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/11/08 13:17:06 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_chars(char *str, char *set)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		if (ft_strchr(set, *str))
			count++;
		str++;
	}
	return (count);
}

/**
 * Removes a all characters in @p remove_set from @p str
 * @param str
 * @param remove_set
 * @return NULL if either @p str or @p remove_set is NULL
 */
char	*ft_str_filter(char *str, char *remove_set)
{
	int		i;
	int		count;
	char	*new_str;

	if (str == NULL || remove_set == NULL)
		return (NULL);
	count = count_chars(str, remove_set);
	new_str = malloc((ft_strlen(str) - count + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i == 0 || *str != '\0')
	{
		if (!ft_strchr(remove_set, *str))
		{
			new_str[i] = *str;
			i++;
		}
		str++;
	}
	new_str[i] = '\0';
	return (new_str);
}
