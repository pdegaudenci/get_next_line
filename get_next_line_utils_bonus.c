/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:16:51 by pdegaude          #+#    #+#             */
/*   Updated: 2022/08/27 17:16:55 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		s_total;

	if (!s1)
		s1 = ft_strdup("");
	if (!s1 || !s2)
		return (NULL);
	s_total = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc((s_total + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_memmove(str, s1, ft_strlen((char *)s1));
	ft_memmove(str + ft_strlen((char *)s1), s2, ft_strlen((char *)s2));
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (dst == src)
		return (dst);
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
		return (dst);
	}
	while (len--)
		*d++ = *s++;
	return (dst);
}

char	*ft_strdup(const char *src)
{
	char	*dst;
	int		cont;

	cont = 0;
	dst = malloc(ft_strlen (src) + 1);
	if (dst == NULL)
		return (NULL);
	while (src[cont] != 0)
	{
		dst[cont] = src[cont];
		cont++;
	}
	dst[cont] = '\0';
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	cont;

	cont = 0;
	while (s[cont] != 0)
		cont++;
	return (cont);
}
