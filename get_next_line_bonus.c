/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkasbaou <hkasbaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:29:25 by hkasbaou          #+#    #+#             */
/*   Updated: 2022/11/15 18:25:44 by hkasbaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

char	*get_first(int fd, char *buff, char *save)
{
	char	*str;
	int		ret;

	ret = 1;
	while (ret > 0 && !ft_strchr(buff, '\n'))
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret < 0)
		{
			free(buff);
			free(save);
			return (NULL);
		}
		buff[ret] = '\0';
		str = ft_strjoin(save, buff);
		free(save);
		save = str;
	}
	free(buff);
	return (str);
}

char	*get_seced(char *save)
{
	int		i;
	char	*str;

	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	str = ft_substr(save, 0, i);
	return (str);
}

char	*get_third(char *save)
{
	int		i;
	char	*str;

	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
	{
		i++;
	}
	if (save[i] == '\n')
		i++;
	str = ft_substr(save, i, ft_strlen(save + i));
	free(save);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*save[MAXFILE];
	char		*lign;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	buff[0] = '\0';
	if (!buff)
		return (NULL);
	save[fd] = get_first(fd, buff, save[fd]);
	if (!save[fd])
		return (NULL);
	if (save[fd][0] == '\0')
	{
		free(save[fd]);
		save[fd] = NULL;
		return (NULL);
	}
	lign = get_seced(save[fd]);
	save[fd] = get_third(save[fd]);
	return (lign);
}
