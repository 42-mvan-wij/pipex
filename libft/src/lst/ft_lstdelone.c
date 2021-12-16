/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 13:07:13 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/11/03 17:38:21 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * deletes a @p lst and calls @p del on its content
 * @param lst
 * @param del NULL, or a function that frees the content of the list contents
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (del != NULL)
		(*del)(lst->content);
	free(lst);
}
