/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft_mem.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/27 14:53:00 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/11/10 15:15:50 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MEM_H
# define LIBFT_MEM_H

# include <stddef.h>

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_malloc(size_t size);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memchr(const void *const_ptr, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memdup(const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memrchr(const void *const_ptr, int c, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_free_arr(void *arr);
void	*ft_free_and_nullify(void **ptr);
void	*ft_free_arr_n(void *arr, size_t n);

#endif
