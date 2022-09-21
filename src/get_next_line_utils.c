/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:15:30 by vasargsy          #+#    #+#             */
/*   Updated: 2022/07/07 11:29:55 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(char *s1)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (s1 == 0)
		return (0);
	dest = malloc(ft_strlen(s1) + 1);
	if (dest == NULL)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (c < 0 || c > 127)
		return ((char *)s);
	while (s[i] || c == 0)
	{
		if (s[i] == c)
		{
			return ((char *)s + i);
		}
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 == 0 && s2 == 0)
		return (0);
	dest = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dest)
		return (0);
	while (s1[i])
		dest[j++] = s1[i++];
	i = 0;
	while (s2[i])
		dest[j++] = s2[i++];
	if (s1)
		free(s1);
	dest[j] = 0;
	return (dest);
}

char	*ft_substr(char	*s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;

	if (!*s || !s)
		return (NULL);
	i = ft_strlen(s);
	j = 0;
	if (start < i)
		j = i - start;
	if (j > len)
		j = len;
	substr = (char *)malloc(sizeof(char) * (j + 1));
	if (!substr)
		return (0);
	i = 0;
	while (s[start] && i < j)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
