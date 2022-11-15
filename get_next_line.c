/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmesrar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 00:08:10 by hmesrar           #+#    #+#             */
/*   Updated: 2022/11/15 00:59:28 by hmesrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static *ptr = NULL;
	char			*line;
	int				readt;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
}

void	ft_read_join(int fd, char *ptr, int readt)
{
	char	*buff;

	// TO FREE
	buff = malloc(sizeof(char)*(BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while(!ft_strchr(ptr, '\n') && readt != 0)
	{
		readt = read (fd, buff, BUFFER_SIZE);
		if ((!ptr && readt == 0) || readt == -1)
			free(buff); // FREED
			return ;
	}
	buff[readt] = '\0';
	ft_join(buff, readt);
}


