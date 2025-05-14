/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:44:50 by arthur            #+#    #+#             */
/*   Updated: 2024/10/22 02:16:02 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	unsigned int	i;
	size_t			len;

	i = 0;
	if (!*s)
		return (NULL);
	len = ft_strlen((char *)s);
	ptr = malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*
char my_function(unsigned int i, char c)
{
    return c + i;
}
int main()
{
	char *result = ft_strmapi("abc", my_function);
	printf("%s", result);
}
*/