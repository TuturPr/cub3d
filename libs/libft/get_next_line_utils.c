/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:35:50 by aperceva          #+#    #+#             */
/*   Updated: 2025/01/08 12:09:59 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	gnl_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (str && str[length])
		length++;
	return (length);
}

size_t	gnl_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	if (!dest || !src)
		return (0);
	i = 0;
	while (i < n - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (n > 0)
		dest[i] = '\0';
	return (gnl_strlen(src));
}

size_t	gnl_strlcat(char *dest, const char *src, size_t n)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	dest_len = gnl_strlen(dest);
	src_len = gnl_strlen(src);
	if (n <= dest_len)
		return (n + src_len);
	i = dest_len;
	j = 0;
	while (src[j] && i + 1 < n)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest_len + src_len);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	total_len;

	if (!s1 || !s2)
		return (NULL);
	total_len = gnl_strlen(s1) + gnl_strlen(s2) + 1;
	result = malloc(total_len);
	if (!result)
		return (NULL);
	gnl_strlcpy(result, s1, gnl_strlen(s1) + 1);
	gnl_strlcat(result, s2, total_len);
	return (result);
}

int	gnl_strchr(const char *s, char c)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
