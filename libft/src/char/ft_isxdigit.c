/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isxdigit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 15:17:56 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/11/03 17:14:29 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *
 * @param c char
 * @returns
 */
int	ft_isxdigit(int c)
{
	return (ft_isdigit(c) || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'));
}
