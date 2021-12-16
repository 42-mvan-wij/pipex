/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_set_digit.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/06 14:59:36 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/11/03 18:16:52 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_nbr.h"

/**
 * Set digit at @p pos in @p num expressed in @p base to @p new_digit
 * @param num
 * @param pos 0 is least significant digit
 * @param new_digit
 * @param base
 * @return new number
 */
int	ft_set_digit(int num, int pos, int new_digit, int base)
{
	const int	prev_digit = ft_get_digit(num, pos, base);
	int			diff;

	diff = prev_digit - new_digit;
	while (pos > 0)
	{
		diff *= base;
		pos--;
	}
	return (num - diff);
}
