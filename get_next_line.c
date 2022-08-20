
#include "get_next_line.h"

char	*ft_get_line(char *buffer)
{
	int		i;
	char	*s;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		s[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		s[i] = buffer[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_save(char *buffer)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!s)
		return (NULL);
	i++;
	c = 0;
	while (buffer[i])
		s[c++] = buffer[i++];
	s[c] = '\0';
	free(buffer);
	return (s);
}

char	*ft_read_and_save(int fd, char *buffer)
{
	char	*buffer_temp;
	int		bytes;

	buffer_temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer_temp)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(buffer_temp, '\n') && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer_temp[bytes] = '\0';
		buffer = ft_strjoin(buffer, buffer);
	}
	free(buffer_temp);
	return (buffer_temp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_read_and_save(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_save(buffer);
	return (line);
}
