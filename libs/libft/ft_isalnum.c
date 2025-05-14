/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:04:01 by aperceva          #+#    #+#             */
/*   Updated: 2024/10/19 10:46:38 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(unsigned char c)
{
	if (((c >= 'a' && c <= 'z')
			|| (c >= 'A' && c <= 'Z')) || (c >= '0' && c <= '9'))
	{
		return (8);
	}
	else
	{
		return (0);
	}
}
/*  int main()
{
	unsigned char	c;

	c = '/';
	printf("%d", isalnum(c));
	printf("%c", '\n');
	printf("%d", ft_isalnum(c));
} */