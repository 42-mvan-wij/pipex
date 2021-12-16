/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 18:24:08 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/11/03 18:25:50 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * Puts @p src into @p dst
 * , until @p dstsize bytes are filled
 * @param dst
 * @param src
 * @param dstsize
 * @return length of @p src
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;

	srcsize = ft_strlen(src);
	if (srcsize + 1 < dstsize)
		ft_memcpy(dst, src, (srcsize + 1) * sizeof(char));
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, (dstsize - 1) * sizeof(char));
		dst[dstsize - 1] = '\0';
	}
	return (srcsize);
}
