/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 08:44:31 by aperceva          #+#    #+#             */
/*   Updated: 2025/01/08 11:15:54 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hexlen(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static void	ft_puthex(unsigned int num, const char format, int fd)
{
	if (num >= 16)
	{
		ft_puthex(num / 16, format, fd);
		ft_puthex(num % 16, format, fd);
	}
	else
	{
		if (num <= 9)
			ft_printchar((num + '0'), fd);
		else
		{
			if (format == 'x')
				ft_printchar((num - 10 + 'a'), fd);
			if (format == 'X')
				ft_printchar((num - 10 + 'A'), fd);
		}
	}
}

int	ft_printhex(unsigned int num, const char format, int fd)
{
	if (num == 0)
		return (write(fd, "0", 1));
	else
		ft_puthex(num, format, fd);
	return (ft_hexlen(num));
}
