/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:52:02 by arthur            #+#    #+#             */
/*   Updated: 2024/10/22 02:21:29 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-", 1);
		write(fd, "2", 1);
		write(fd, "147483648", 9);
	}
	else
	{
		if (n < 0)
		{
			ft_putchar_fd(('-'), fd);
			n = -n;
		}
		if (n >= 10)
		{
			ft_putnbr_fd((n / 10), fd);
		}
		ft_putchar_fd((n % 10 + '0'), fd);
	}
}
/*
int main()
{
	ft_putnbr_fd(4836468);	
	return (0);
}
*/
