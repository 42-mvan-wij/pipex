/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 12:29:59 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/11/03 17:28:19 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * Prints @p c to @p fd
 * @param c char
 * @param fd file descriptor
 * @returns
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
