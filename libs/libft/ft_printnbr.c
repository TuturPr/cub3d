/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:52:02 by arthur            #+#    #+#             */
/*   Updated: 2025/01/08 11:16:33 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printnbr(int nb, int fd)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		count += write(fd, "-", 1);
		count += write(fd, "2", 1);
		count += write(fd, "147483648", 9);
	}
	else
	{
		if (nb < 0)
		{
			count += ft_printchar('-', fd);
			nb = -nb;
		}
		if (nb >= 10)
		{
			count += ft_printnbr(nb / 10, fd);
		}
		count += ft_printchar(nb % 10 + '0', fd);
	}
	return (count);
}

/* int main()
{
	ft_putchar_fd(48368, 1);
	return (0);
} */
