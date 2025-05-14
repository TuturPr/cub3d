/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:10:53 by aperceva          #+#    #+#             */
/*   Updated: 2024/10/19 10:47:12 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*src1;
	const unsigned char	*src2;

	src1 = s1;
	src2 = s2;
	i = 0;
	while (i < n && src1[i] != '\0' && src2[i] != '\0')
	{
		if (src1[i] != src2[i])
			return (src1[i] - src2[i]);
		i++;
	}
	if (i < n)
		return (src1[i] - src2[i]);
	return (0);
}
/* int main()
{
    char str[50] = "world Hello eu";
    char str1[50] = "z";
    printf("%d", ft_memcmp(str, str1, 6));
} */
