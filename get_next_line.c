/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:45:14 by pdegaude          #+#    #+#             */
/*   Updated: 2022/08/27 15:45:43 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *buffer)
{
	int		i;
	char	*temp;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	temp = (char *)malloc(sizeof(char) * (i + 2));
	if (!temp)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		temp[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		temp[i] = buffer[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_save_newbuffer(char *buffer)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	temp = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!temp)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		temp[j++] = buffer[i++];
	temp[j] = '\0';
	free(buffer);
	return (temp);
}

char	*ft_create_buffer(int fd, char *buffer)
{
	char	*buffer_temp;
	int		bytes;

	buffer_temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer_temp)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(buffer, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer_temp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer_temp);
			return (NULL);
		}
		buffer_temp[bytes] = '\0';
		buffer = ft_strjoin(buffer, buffer_temp);
	}
	free(buffer_temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_create_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_save_newbuffer(buffer);
	return (line);
}
