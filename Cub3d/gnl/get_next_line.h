/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:33:41 by ydegerli          #+#    #+#             */
/*   Updated: 2022/12/01 16:34:20 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(const char *s);

char	*ft_strchr(const char *s, int c);

char	*add(char *s1, char *s2);

char	*scan(int fd, char *s);

char	*line(char *str);

char	*next(char *s);

char	*get_next_line(int fd);

#endif
