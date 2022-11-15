/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmesrar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 00:47:00 by hmesrar           #+#    #+#             */
/*   Updated: 2022/11/15 18:33:30 by hmesrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_to(char *str, char c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int	ft_strchr(char *str, char c)
{
	int	i;
	int n;

	i = 0;
	n = ft_strlen_to(str, '\0');
	while (n--)
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*join;

	len = ft_strlen_to(s1, '\0') + ft_strlen_to(s2, '\0');
	join = malloc((len + 1) * sizeof(char));
	if (!join)
		return (0);
	i = -1;
	j = 0;
	while (s1[++i])
		join[i] = s1[i];
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = '\0';
	// TO FREE S1 and S2
	return (join);
}

char	*ft_substr(char *s, size_t start, size_t len)
{
	size_t	i;
	char	*sub;
	size_t	len_to_alloc;

	i = 0;
	if (!s)
		return (0);
	if ((ft_strlen_to(s, '\0') - start) < len)
		len_to_alloc = ft_strlen_to(s, '\0') - start;
	else
		len_to_alloc = len;
	if (start >= ft_strlen_to(s, '\0'))
		return (ft_strdup(""));
	sub = (char *)malloc(len_to_alloc * sizeof(char) + 1);
	if (!sub)
		return (0);
	while (s[start + i] && i < len_to_alloc)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	// TO FREE IF NECESSARY
	return (sub);
}

char	*ft_strdup(char *s1)
{
	char	*dup;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen_to(s1, '\0');
	dup = (char *)malloc(len * sizeof(char) + 1);
	if (!dup)
		return (0);
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	// TO FREE IF NECESSARY
	return (dup);
}
