/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft_io.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/27 14:57:31 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/07/28 13:14:34 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_IO_H
# define LIBFT_IO_H

void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
// Returns number of characters printed
int		ft_putnbr_base_fd(long long nbr, char *basechars, int fd);
// Returns number of characters printed
int		ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

#endif
