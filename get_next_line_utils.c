#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	stot_len;
	char	*rtn;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen(s2);
	stot_len = s1_len + s2_len + 1;
	rtn = malloc(sizeof(char) * stot_len);
	if (!rtn)
		return (0);
	ft_memmove(rtn, s1, s1_len);
	ft_memmove(rtn + s1_len, s2, s2_len);
	rtn[stot_len - 1] = '\0';
	return (rtn);
}

char	*ft_strchr(const char *s, int c)
{
	int	cont;

	cont = 0;
	while (*(s + cont))
	{
		if (*(s + cont) == (char )c)
			return ((char *)s + cont);
		cont++;
	}
	if (*(s + cont) == (char)c)
		return ((char *)s + cont);
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
