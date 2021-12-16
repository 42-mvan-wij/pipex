/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft_tree.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/27 14:50:40 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/07/27 14:57:10 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TREE_H
# define LIBFT_TREE_H

typedef struct s_tree
{
	void			*content;
	struct s_tree	*left;
	struct s_tree	*right;
}	t_tree;

t_tree	*ft_treenew(void *content, t_tree *left, t_tree *right);

#endif
