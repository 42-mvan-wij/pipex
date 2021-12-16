/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 11:04:32 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/11/03 18:21:30 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * Duplicates @p s with malloc
 * @param s
 * @return NULL on failure
 */
char	*ft_strdup(const char *s)
{
	int		len;
	char	*new_s;

	len = ft_strlen(s) + 1;
	new_s = malloc(len * sizeof(char));
	if (new_s == NULL)
		return (NULL);
	while (len > 0)
	{
		new_s[len - 1] = s[len - 1];
		len--;
	}
	return (new_s);
}
