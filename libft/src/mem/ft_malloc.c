/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_malloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/15 12:55:05 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/05/17 12:43:16 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#ifndef PRINT_MALLOC_FAIL
# define PRINT_MALLOC_FAIL 1
#endif

void	*ft_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		if (PRINT_MALLOC_FAIL + 0)
			write(STDOUT_FILENO, "Error: Malloc failed\n", 21);
		exit(EXIT_FAILURE);
	}
	return (ptr);
}
