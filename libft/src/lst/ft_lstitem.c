/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstitem.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/06 14:09:59 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/11/03 17:40:29 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_lst.h"
#include <stdlib.h>

/**
 * Gets item at index @p i in @p lst
 * @param lst
 * @param i
 * @return NULL on failure
 */
t_list	*ft_lstitem(t_list *lst, int i)
{
	if (lst == NULL)
		return (NULL);
	while (i > 0)
	{
		lst = lst->next;
		i--;
	}
	return (lst);
}
