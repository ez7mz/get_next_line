/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmesrar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 00:08:10 by hmesrar           #+#    #+#             */
/*   Updated: 2022/11/18 18:28:26 by hmesrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_line(int fd, char *ptr)
{
	char	*buff;
	ssize_t	readt;

	if (!ptr)
		ptr = ft_strdup("");
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (free(ptr), NULL);
	while (!ft_strchr(ptr, '\n'))
	{
		readt = read(fd, buff, BUFFER_SIZE);
		if (readt < 0)
			return (free(ptr), free(buff), NULL);
		buff[readt] = '\0';
		ptr = ft_strjoin(ptr, buff);
		if (readt == 0 && ptr[0] == '\0')
			return (free(ptr), free(buff), NULL);
		else if (readt == 0)
			return (free(buff), ptr);
	}
	free(buff);
	return (ptr);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*ptr;
	int			pos;
	int			end_pos;
	char		*tmp;

	ptr = ft_read_line(fd, ptr);
	tmp = ptr;
	if (!ptr)
		return (NULL);
	pos = ft_strlen_to(ptr, '\n');
	end_pos = ft_strlen_to(ptr, '\0');
	line = ft_substr(ptr, 0, pos + 1);
	ptr = ft_substr(ptr, pos + 1, end_pos - pos);
	free(tmp);
	return (line);
}
