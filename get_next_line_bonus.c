/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmesrar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:07:44 by hmesrar           #+#    #+#             */
/*   Updated: 2022/11/17 14:47:05 by hmesrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_read_line(int fd ,char *ptr)
{
	char	*buff;
	ssize_t	readt;

	if (!ptr)
		ptr = ft_strdup("");
	buff = malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (free(ptr), NULL); // TO FREE
	readt = 1;
	while (!ft_strchr(ptr, '\n'))
	{
		readt = read(fd, buff, BUFFER_SIZE);
		if (readt < 0)
			return (free(ptr), free(buff), NULL); // TO FREE ptr and buff
		buff[readt] = '\0';
		ptr = ft_strjoin(ptr, buff);
		if (readt == 0 && ptr[0] == '\0')
				return (free(ptr), free(buff), NULL); // TO FREE ptr and buff
		else if (readt == 0)
			return (free(buff), ptr); // TO FREE buff
	}
	free(buff);
	return (ptr);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*ptr[OPEN_MAX];
	int			pos;
	int			end_pos;
	char		*tmp;

	ptr[fd] = ft_read_line(fd, ptr[fd]);
	tmp = ptr[fd];
	if (!ptr[fd])
		return (NULL);
	pos = ft_strlen_to(ptr[fd], '\n');
	end_pos = ft_strlen_to(ptr[fd], '\0');
	line = ft_substr(ptr[fd], 0, pos + 1);
	ptr[fd] = ft_substr(ptr[fd], pos + 1, end_pos - pos);
	free(tmp);
	return (line);
}
