/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:48:03 by pdegaude          #+#    #+#             */
/*   Updated: 2022/08/27 15:49:03 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *string, int searchedChar );
char	*ft_strdup(const char *src);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlen(const char *theString);
char	*ft_create_buffer(int fd, char *buffer);
char	*ft_read_line(char *buffer);
#endif
