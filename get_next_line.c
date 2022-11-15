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

static char	*ft_read_file(int fd ,char *ptr)
{
	char	*buff;
	int 	readt;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	readt = 1;
	while (!ft_strchr(ptr, '\n')&& readt != 0)
	{
		readt = read (fd, buff, BUFFER_SIZE);
		if ((!ptr && readt == 0) || readt == -1)
			return (free(buff), NULL); // FREED
		buff[readt] = '\0';
		ptr = ft_strjoin(ptr, buff);
	}
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char		*ptr;
	char			*line;
	int				pos;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	ptr = ft_strdup("");
	ptr = ft_read_file(fd, ptr);
	if (!ptr)
		return (NULL);
	pos = ft_strchr(ptr, '\n');
	line = ft_substr(ptr, 0, pos);
	// printf("before : | %s |\n", ptr);
	ptr = ft_substr(ptr, pos + 1, ft_strlen(ptr) - pos);
	// printf("after  : | %s |\n", ptr);
	return (line);
}



int main()
{
	int fd = open("file.txt", O_RDONLY);
	// char p[6];
	// read (fd, p, 5);
	char *line = get_next_line(fd);
	char *line1 = get_next_line(fd);
	char *line2 = get_next_line(fd);
	char *line3 = get_next_line(fd);
	char *line4 = get_next_line(fd);
	printf("%s\n", line);
	printf("%s\n", line1);
	printf("%s\n", line2);
	printf("%s\n", line3);
	printf("%s\n", line4);
	// printf("%s", p);
}
// Hello world\n
