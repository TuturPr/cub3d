/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:01:05 by aperceva          #+#    #+#             */
/*   Updated: 2024/10/19 10:46:48 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(unsigned char c)
{
	if (c >= '0' && c <= '9')
	{
		return (2048);
	}
	else
	{
		return (0);
	}
}
/* int main()
{
	unsigned char	c;

	c = '1';
	printf("%d", isdigit(c));
	printf("%c", '\n');
	printf("%d", ft_isdigit(c));
} */