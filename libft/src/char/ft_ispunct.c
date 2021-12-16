/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ispunct.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 15:20:21 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/11/03 17:14:19 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *
 * @param c char
 * @returns
 */
int	ft_ispunct(int c)
{
	return (ft_isprint(c) && !ft_isalnum(c));
}
