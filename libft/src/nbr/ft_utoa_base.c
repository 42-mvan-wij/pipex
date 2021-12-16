/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 10:43:04 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/11/03 18:17:11 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdint.h>

/**
 * Converts unsigned @p nbr to a string in base: length of @p basechars
 * , using characters from @p basechars
 * @param nbr
 * @param basechars
 * @return NULL on failure
 */
char	*ft_utoa_base(uint64_t nbr, char *basechars)
{
	size_t	base;
	uint8_t	i;
	char	*res;

	if (basechars == NULL)
		return (NULL);
	base = ft_strlen(basechars);
	if (base < 2)
		return (NULL);
	i = ft_nbrlen_u(nbr, base);
	res = ft_calloc(i + 1, sizeof(char));
	while (i != 0)
	{
		i--;
		res[i] = basechars[nbr % base];
		nbr /= base;
	}
	return (res);
}
