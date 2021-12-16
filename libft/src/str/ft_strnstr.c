/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 11:11:05 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/11/03 18:29:45 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * Searches for @p little in the first @p len bytes of @p big
 * @param big
 * @param little
 * @param len
 * @return NULL if @p little cannot be found,
 * otherwise pointer to first matching character
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_little;
	char	*b;

	if (big == NULL || little == NULL)
		return (NULL);
	if (little[0] == '\0')
		return ((char *)big);
	b = (char *)big;
	len_little = ft_strlen(little);
	while (len >= len_little)
	{
		len--;
		if (ft_memcmp(b, little, len_little) == 0)
			return (b);
		b++;
	}
	return (NULL);
}
