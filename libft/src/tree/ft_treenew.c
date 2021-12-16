/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_treenew.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/15 13:22:05 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/05/15 13:29:36 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_tree	*ft_treenew(void *content, t_tree *left, t_tree *right)
{
	t_tree	*tree;

	tree = malloc(sizeof(t_tree));
	if (tree == NULL)
		return (NULL);
	tree->content = content;
	tree->left = left;
	tree->right = right;
	return (tree);
}
