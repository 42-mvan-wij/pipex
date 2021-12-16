/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_iscntrl.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 15:25:24 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/11/03 17:14:05 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *
 * @param c char
 * @returns
 */
int	ft_iscntrl(int c)
{
	return (!ft_isprint(c));
}
