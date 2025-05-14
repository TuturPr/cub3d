/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:46:42 by arthur            #+#    #+#             */
/*   Updated: 2025/01/08 11:17:23 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printstr(char *s, int fd)
{
	int	length;

	length = 0;
	if (!s)
		return (write(fd, "(null)", 6), 6);
	while (s[length])
	{
		length++;
	}
	return (write(fd, s, length));
}
