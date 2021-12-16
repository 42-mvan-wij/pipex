/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 18:11:27 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/11/03 18:04:27 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * Copies @p len bytes from @p src to @p dst in a non destructive manner
 * @param dst
 * @param src
 * @param len
 * @return @p dst
 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;

	if (dst == src)
		return (dst);
	if (dst > src)
		return (ft_memcpy(dst, src, len));
	i = 0;
	while (i < len)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}
