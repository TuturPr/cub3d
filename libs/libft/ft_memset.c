/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:25:11 by aperceva          #+#    #+#             */
/*   Updated: 2024/10/19 10:47:22 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*mem;

	mem = s;
	i = 0;
	while (i < n)
	{
		mem[i] = c;
		i++;
	}
	return (mem);
}
/* int	main(void)
{
	char str[50] = "Hello World";

	
	printf("Original string: %s\n", str);

	
	ft_memset(str, 'X', 5);

	
	printf("Modified string: %s\n", str);

	return 0;
} */
