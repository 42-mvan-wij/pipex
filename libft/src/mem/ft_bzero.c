/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 17:49:25 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/11/03 18:26:04 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * Sets @p n bytes at @p s to zero
 * @param s
 * @param n
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
