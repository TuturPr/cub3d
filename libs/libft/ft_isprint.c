/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:54:35 by aperceva          #+#    #+#             */
/*   Updated: 2024/10/19 10:46:56 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(unsigned char c)
{
	if (c >= 32 && c <= 126)
	{
		return (16384);
	}
	else
	{
		return (0);
	}
}
/* int main()
{
	unsigned char	c;

	c = 0xEA;
	printf("%d", isprint(c));
	printf("%c", '\n');
	printf("%d", ft_isprint(c));
} */