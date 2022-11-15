/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkasbaou <hkasbaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:29:35 by hkasbaou          #+#    #+#             */
/*   Updated: 2022/11/15 18:23:10 by hkasbaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	s = malloc(count * size);
	if (!s)
	{
		free(s);
		return (NULL);
	}
	ft_bzero(s, count * size);
	return (s);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	if (!(char)c)
		return ((char *)str + i);
	return (0);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	ttl;
	char	*str;
	size_t	i;
	int		j;

	i = -1;
	j = 0;
	if (!s1)
		s1 = "";
	ttl = ft_strlen(s2) + ft_strlen(s1);
	str = ft_calloc((ttl + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*str;
	int		siz;

	siz = start;
	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return ((char *)ft_calloc(1, sizeof(char)));
	if (ft_strlen(s) <= start + len)
		str = ft_calloc(sizeof(char), (ft_strlen(s) - start + 1));
	else
		str = ft_calloc(sizeof(char), (len + 1));
	if (!str)
		return (NULL);
	while (s[start] && start < len + siz)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	return (str);
}
///////////////////////////////////