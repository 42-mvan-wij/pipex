/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft_gnl.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/27 14:59:34 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/07/28 13:13:19 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_GNL_H
# define LIBFT_GNL_H

/**
 * Sets *line to the next line of fd or NULL on error
 * Returns 0 on EOF, -1 on error, otherwise returns 1,
 * Errors: fd < 0, BUFFER_SIZE < 0, line == NULL, or a system error
 */
int		get_next_line(int fd, char **line);

#endif
