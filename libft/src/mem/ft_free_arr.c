/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_arr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: marius <marius@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/26 20:37:34 by marius        #+#    #+#                 */
/*   Updated: 2021/11/03 17:55:41 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft_mem.h"

/**
 * Frees and nullifies *@p arr
 * @param arr &(void **)arr (NULL terminated)
 * @return NULL
 */
void	*ft_free_arr(void *arr)
{
	int		i;
	void	**a;

	i = 0;
	a = *(void ***)arr;
	while (a[i] != NULL)
	{
		ft_free_and_nullify(&a[i]);
		i++;
	}
	ft_free_and_nullify(arr);
	return (NULL);
}
