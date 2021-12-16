/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 10:58:19 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/11/03 18:20:47 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * Search for last occurrence of @p c in @p s
 * @param s
 * @param c
 * @return NULL if @p c cannot be found
 */
char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	cc;
	char	*cs;

	cc = (char)c;
	cs = (char *)s;
	i = ft_strlen(s) - 1;
	if (cc == '\0')
		return (cs + i + 1);
	while (i >= 0)
	{
		if (s[i] == cc)
			return (cs + i);
		i--;
	}
	return (NULL);
}
