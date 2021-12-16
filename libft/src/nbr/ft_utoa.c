/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 15:25:07 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/11/03 18:17:39 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdint.h>

/**
 * Converts unsigned @p nbr to a string in base 10
 * @param nbr
 * @return NULL on failure
 */
char	*ft_utoa(uint64_t nbr)
{
	uint8_t	i;
	char	*res;

	i = ft_nbrlen_u(nbr, 10);
	res = ft_calloc(i + 1, sizeof(char));
	while (i != 0)
	{
		i--;
		res[i] = '0' + (nbr % 10);
		nbr /= 10;
	}
	return (res);
}
