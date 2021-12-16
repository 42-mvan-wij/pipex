/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memdup.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/25 12:51:32 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/03/11 23:32:24 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * Duplicates @p n bytes of @p src with malloc
 * @param src
 * @param n
 * @return NULL on failure
 */
void	*ft_memdup(const void *src, size_t n)
{
	void	*dst;

	dst = malloc(n);
	if (dst == NULL)
		return (NULL);
	return (ft_memmove(dst, src, n));
}
