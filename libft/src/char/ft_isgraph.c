/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isgraph.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 15:21:58 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/11/03 17:14:11 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *
 * @param c char
 * @returns
 */
int	ft_isgraph(int c)
{
	return (c != ' ' && ft_isprint(c));
}
