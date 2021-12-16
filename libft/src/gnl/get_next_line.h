/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 16:18:18 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/07/27 15:05:13 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft_gnl.h"
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

typedef struct s_buffer
{
	char			*str;
	ssize_t			size;
	ssize_t			start;
	struct s_buffer	*next;
}					t_buffer;

t_buffer	*gnl_new_buffer(ssize_t size);
int			gnl_error(t_buffer **buf_arr);
int			gnl_error_fd(int fd, t_buffer **buf_arr);
void		gnl_next(t_buffer **buf);

#endif
