/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft_nbr.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/27 14:51:23 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/11/03 18:26:02 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_NBR_H
# define LIBFT_NBR_H

# include <stdint.h>

double	ft_atod(char *s);
int		ft_atoi(const char *str);
char	*ft_itoa_base(int64_t nbr, char *basechars);
char	*ft_itoa_basei(int64_t nbr, uint8_t base, int cap);
char	*ft_itoa(int64_t nbr);
uint8_t	ft_nbrlen_u(uint64_t nbr, uint64_t base);
uint8_t	ft_nbrlen(int64_t nbr, uint32_t base);
char	*ft_utoa_base(uint64_t nbr, char *basechars);
char	*ft_utoa_basei(uint64_t nbr, uint8_t base, int cap);
char	*ft_utoa(uint64_t nbr);
int		ft_get_digit(int num, int pos, int base);
int		ft_set_digit(int num, int pos, int new_digit, int base);

#endif
