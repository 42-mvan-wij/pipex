/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_and_nullify.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: marius <marius@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/26 20:38:11 by marius        #+#    #+#                 */
/*   Updated: 2021/11/10 15:15:23 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * Frees and nullifies *@p ptr
 * @param ptr &(void *)ptr
 * @return NULL
 */
void	*ft_free_and_nullify(void *ptr)
{
	void	**p;

	p = (void **)ptr;
	free(*p);
	*p = NULL;
	return (NULL);
}
