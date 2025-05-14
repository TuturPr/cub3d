/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:24:47 by aperceva          #+#    #+#             */
/*   Updated: 2024/10/19 10:48:12 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_strlen((char *)little);
	if (!little[0])
		return ((char *)big);
	while (big[j] && i <= len - j)
	{
		if (ft_strncmp((char *)big + j, (char *)little, i) == 0)
			return ((char *)big + j);
		j++;
	}
	return (NULL);
}
/* int main()
{
    char str[50] = "world Hello eu";
    char str1[50] = "Hello";
    printf("%s", ft_strnstr(str, str1, 14));
} */