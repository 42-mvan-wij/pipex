/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_arr_n.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: marius <marius@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/26 21:12:17 by marius        #+#    #+#                 */
/*   Updated: 2021/11/03 18:26:09 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft_mem.h"

/**
 * Frees and nullifies *@p arr
 * @param arr &(void **)arr
 * @param n length of array
 * @return NULL
 */
void	*ft_free_arr_n(void *arr, size_t n)
{
	size_t	i;
	void	**a;

	i = 0;
	a = *(void ***)arr;
	while (i < n)
	{
		ft_free_and_nullify(&a[i]);
		i++;
	}
	ft_free_and_nullify(arr);
	return (NULL);
}
