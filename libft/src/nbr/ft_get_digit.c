/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_get_digit.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/06 15:00:20 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/11/03 18:15:37 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/**
 * Get digit at @p pos in @p num expressed in @p base
 * @param num
 * @param pos 0 is least significant digit
 * @param base
 * @return
 */
int	ft_get_digit(int num, int pos, int base)
{
	while (pos > 0)
	{
		num /= base;
		pos--;
	}
	return (num % base);
}
