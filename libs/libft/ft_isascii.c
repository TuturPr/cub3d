/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:10:35 by aperceva          #+#    #+#             */
/*   Updated: 2024/10/19 10:46:45 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(unsigned char c)
{
	if (c > 127)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}
/*  int main()
{
	unsigned char	c;

	c = 0xAE;
	printf("%d", isascii(c));
	printf("%c", '\n');
	printf("%d", ft_isascii(c));
} */