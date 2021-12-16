/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 11:30:22 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/11/03 18:22:10 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * Concatenates @p s1 and @p s2
 * @param s1
 * @param s2
 * @return NULL on failure
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*dst;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	dst = malloc(len * sizeof(char));
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, s1, len);
	ft_strlcat(dst, s2, len);
	return (dst);
}
