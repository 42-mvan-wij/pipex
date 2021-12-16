/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_nbrlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/24 16:50:36 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/11/03 18:13:26 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

/**
 * Get the length of @p nbr in base: @p base
 * , if nbr is 0 return value is 1, signs do not count towards length
 * @param nbr
 * @param base
 * @return
 */
uint8_t	ft_nbrlen(int64_t nbr, uint32_t base)
{
	uint8_t		i;

	i = 1;
	if (nbr < 0)
		i++;
	while (nbr / base != 0)
	{
		nbr /= base;
		i++;
	}
	return (i);
}
