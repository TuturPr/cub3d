/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:58:22 by aperceva          #+#    #+#             */
/*   Updated: 2024/10/19 10:47:18 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*desti;
	const unsigned char	*source;
	unsigned long		i;

	desti = dest;
	source = src;
	if (desti > source && desti < source + n)
	{
		i = n;
		while (i-- > 0)
			desti[i] = source[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			desti[i] = source[i];
			i++;
		}
	}
	return (desti);
}
/* int main()
{
	char src1[] = "1234567890";
	char src2[] = "1234567890";

	// Chevauchement avec memcpy
	printf("Avant memcpy : %s\n", src1);
	memcpy(src1 + 1, src1, 5);  
	printf("Après memcpy : %s\n", src1);

	// Chevauchement avec memmove
	printf("\nAvant memmove : %s\n", src2);
	ft_memmove(src2 + 1, src2, 5);  
	printf("Après memmove : %s\n", src2);

	return 0;
} */