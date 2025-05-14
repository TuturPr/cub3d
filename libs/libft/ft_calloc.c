/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:28:49 by aperceva          #+#    #+#             */
/*   Updated: 2025/01/07 15:09:32 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*var;

	var = malloc(nmemb * size);
	if (var == 0)
		return (NULL);
	ft_bzero(var, nmemb * size);
	return (var);
}
