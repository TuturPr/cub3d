/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 07:33:44 by aperceva          #+#    #+#             */
/*   Updated: 2025/01/08 12:09:40 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_ptrlen(uintptr_t ptr)
{
	size_t	total;

	total = 0;
	if (ptr <= 0)
		total++;
	while (ptr)
	{
		total++;
		ptr /= 16;
	}
	return (total);
}

static void	ft_putptr(uintptr_t ptr, int fd)
{
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16, fd);
		ft_putptr(ptr % 16, fd);
	}
	else
	{
		if (ptr <= 9)
			ft_printchar(ptr + '0', fd);
		else
			ft_printchar(ptr - 10 + 'a', fd);
	}
}

int	ft_printptr(unsigned long long ptr, int fd)
{
	int	count;

	count = 0;
	if (ptr == 0)
		return (write(fd, "(nil)", 5));
	else
	{
		count += write(fd, "0x", 2);
		count += ft_ptrlen(ptr);
		ft_putptr(ptr, fd);
	}
	return (count);
}
