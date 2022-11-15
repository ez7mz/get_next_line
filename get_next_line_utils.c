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

int	ft_strchr(char *s, int c)
{
	int		n;
	char	test;
	int		i;

	if (!s)
		return (0);
	n = ft_strlen(s) + 1;
	test = c;
	i = 0;
	while (n--)
	{
		if (*s == test)
			return (i);
		s++;
		i++;
	}
	return (0);
}


char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		len;
	int		i;
	int		j;

	if (!s1)
		return (ft_strdup(""));
	if (!s1 || !s2)
		return (NULL);
	i = -1;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	// TO FREE
	join = (char *)malloc(sizeof(char) * (len + 1));
	if (!join)
		return (0);
	while (s1[++i])
		join[i] = s1[i];
	while (s2[j])
		join[i++] = s2[j++];
	join[len] = '\0';
	return (join);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
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
	while (s[start + i] && i < len_to_alloc)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	// (void)ft_strlcpy(sub, s + start, len_to_alloc + 1);
	return (sub);
}

char	*ft_strdup(char *s1)
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
