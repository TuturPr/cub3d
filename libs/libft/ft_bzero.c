/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:19:45 by aperceva          #+#    #+#             */
/*   Updated: 2024/10/19 10:46:26 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned long	i;
	unsigned char	*mem;

	mem = s;
	i = 0;
	while (i < n)
	{
		mem[i] = '\0';
		i++;
	}
	return (mem);
}
/* int	main(void)
{
	char str[50] = "Hello World";

	
	printf("Original string: %s\n", str);

	
	ft_bzero(str, 1);

	
	printf("Modified string: %s\n", str);

	return 0;
} */
