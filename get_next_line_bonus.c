/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimaozi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:18:04 by msimaozi          #+#    #+#             */
/*   Updated: 2022/12/01 17:18:06 by msimaozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_save(char *save)
{
	int		x;
	int		y;
	char	*dest;

	x = 0;
	while (save[x] && save[x] != '\n')
		x++;
	if (!save[x])
	{
		free(save);
		return (0);
	}
	dest = malloc(((ft_strlen(save) - x) + 1) * sizeof(char));
	if (!dest)
		return (0);
	x++;
	y = 0;
	while (save[x])
		dest[y++] = save[x++];
	dest[y] = '\0';
	free(save);
	return (dest);
}

char	*ft_getline(char *save)
{
	size_t	x;
	size_t	y;
	char	*line;

	x = 0;
	y = 0;
	if (!save[x])
		return (0);
	while (save[x] && save[x] != '\n')
		x++;
	line = malloc((x + 2) * sizeof(char));
	if (!line)
		return (0);
	while (y <= x)
	{
		line[y] = save[y];
		y++;
	}
	line[y] = '\0';
	return (line);
}

char	*ft_readsave(int fd, char *save)
{
	char	*buf;
	int		readbyte;

	while (ft_strchr(save))
		return (save);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	readbyte = 1;
	while (!ft_strchr(save) && readbyte > 0)
	{
		readbyte = read(fd, buf, BUFFER_SIZE);
		if (readbyte == -1)
		{
			free(buf);
			free(save);
			return (0);
		}
		buf[readbyte] = '\0';
		save = ft_strjoin(save, buf);
	}
	free(buf);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save[FOPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (0);
	save[fd] = ft_readsave(fd, save[fd]);
	if (!save[fd])
		return (0);
	line = ft_getline(save[fd]);
	save[fd] = ft_save(save[fd]);
	return (line);
}
