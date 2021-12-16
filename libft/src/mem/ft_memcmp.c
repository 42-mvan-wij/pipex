/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 18:17:55 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/11/03 18:01:14 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * Compares @p n bytes of memory at @p s1 and @p s2
 * @param s1
 * @param s2
 * @param n
 * @return 0 if equal, *@p s1 - *@p s2 where a difference has been found
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	char			*cs1;
	char			*cs2;
	char			*ucs1;
	char			*ucs2;

	cs1 = (char *)s1;
	cs2 = (char *)s2;
	ucs1 = (char *)s1;
	ucs2 = (char *)s2;
	i = 0;
	while (i < n)
	{
		if (cs1[i] != cs2[i])
			return (ucs1[i] - ucs2[i]);
		i++;
	}
	return (0);
}
