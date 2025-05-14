/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:55:05 by arthur            #+#    #+#             */
/*   Updated: 2024/10/21 15:27:23 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen((char *)src);
	if (n == 0)
		return (src_len);
	if (n <= dest_len)
		return (n + src_len);
	i = dest_len;
	j = 0;
	while (src[j] != '\0' && i + 1 < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (i < n)
		dest[i] = '\0';
	return (dest_len + src_len);
}
/* int main()
{
	char test[50] = "Hello";
	char test2[50] = "World";
    
	printf("%zu", ft_strlcat(test, test2, 10));
	printf("%c", '\n');
	printf("%s", test);
} */