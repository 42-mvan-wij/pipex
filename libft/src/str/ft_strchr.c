/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 10:36:48 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/11/03 18:25:59 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * Search for first occurrence of @p c in @p s
 * @param s
 * @param c
 * @return NULL if @p c cannot be found
 */
char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	cc;
	char	*cs;

	cc = (char)c;
	cs = (char *)s;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == cc)
			return (cs + i);
		i++;
	}
	if (c == '\0')
		return (cs + i);
	return (NULL);
}
