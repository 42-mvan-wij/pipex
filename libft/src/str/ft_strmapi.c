/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 12:18:41 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/11/03 18:27:22 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * Maps @p s to a new string with @p f called on each character
 * @param s
 * @param f
 * @return NULL on failure
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	char	*mapped;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	mapped = malloc((len + 1) * sizeof(char));
	if (mapped == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		mapped[i] = f(i, s[i]);
		i++;
	}
	mapped[i] = '\0';
	return (mapped);
}
