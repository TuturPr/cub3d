/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:46:31 by aperceva          #+#    #+#             */
/*   Updated: 2024/10/19 11:07:30 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dest, const char *src, size_t n)
{
	unsigned int	i;
	int				src_len;

	src_len = ft_strlen((char *)src);
	i = 0;
	if (n == 0)
	{
		return (src_len);
	}
	while (i < n - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}
/* int	main(void)
{
	char str2[50] = "123456789";
	char str[50] = "world Hello eu";

	
	printf("%s", ft_strlcpy(str, str2, 12));

	
	

	return 0;
} */