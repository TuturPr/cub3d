/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:52:02 by arthur            #+#    #+#             */
/*   Updated: 2025/01/08 11:17:40 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printunbr(unsigned int nb, int fd)
{
	int	count;

	count = 0;
	if (nb >= 10)
		count += ft_printunbr(nb / 10, fd);
	count += ft_printchar(nb % 10 + '0', fd);
	return (count);
}

/* int main()
{
	ft_putchar_fd(48368, 1);
	return (0);
} */
