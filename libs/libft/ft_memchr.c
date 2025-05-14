/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:41:24 by aperceva          #+#    #+#             */
/*   Updated: 2024/10/19 10:47:09 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*src;
	unsigned char		ch;
	size_t				i;

	src = s;
	ch = c;
	i = 0;
	while (*src && (*src != ch) && i + 1 < n)
	{
		src++;
		i++;
	}
	if (*src == ch)
	{
		return ((char *)src);
	}
	return (NULL);
}
/* int main()
{
    char str[50] = "world Hello eu";
    char str1 = 'H';
    printf("%s", (char *)ft_memchr(str, str1, 6));
} */
