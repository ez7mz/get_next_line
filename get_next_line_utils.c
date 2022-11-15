/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmesrar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 00:47:00 by hmesrar           #+#    #+#             */
/*   Updated: 2022/11/15 00:56:30 by hmesrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	contains_newline(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (!dst && dstsize == 0)
		return (src_len + dstsize);
	dst_len = ft_strlen(dst);
	i = 0;
	if (dstsize == 0 || dstsize <= dst_len)
		return (src_len + dstsize);
	(void)ft_strlcpy(dst + dst_len, src, dstsize - dst_len);
	return (src_len + dst_len);
}

char	*ft_join(char *s1, char *s2)
{
	char	*join;
	int		len;
	int		i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	// TO FREE
	join = (char *)malloc(len * sizeof(char) + 1);
	if (!join)
		return (0);
	(void)ft_strlcpy(join, s1, ft_strlen(s1) + 1);
	(void)ft_strlcat(join, s2, len + 1);
	return (join);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;
	size_t	len_to_alloc;

	i = 0;
	if (!s)
		return (0);
	if ((ft_strlen(s) - start) < len)
		len_to_alloc = ft_strlen(s) - start;
	else
		len_to_alloc = len;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	// TO FREE
	sub = (char *)malloc(len_to_alloc * sizeof(char) + 1);
	if (!sub)
		return (0);
	(void)ft_strlcpy(sub, s + start, len_to_alloc + 1);
	return (sub);
}

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	// TO FREE
	dup = (char *)malloc(len * sizeof(char) + 1);
	if (!dup)
		return (0);
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
