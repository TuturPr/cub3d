/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:43:22 by aperceva          #+#    #+#             */
/*   Updated: 2025/01/08 12:08:54 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, char c)
{
	if (!s)
		return (NULL);
	while (*s && (*s != c))
	{
		s++;
	}
	if (*s == c)
	{
		return ((char *)s);
	}
	return (NULL);
}
/* int main()
{
    char str[50] = "world Hello eu";
    char str1 = 'z';
    printf("%s", ft_strchr(str, str1));
} */
