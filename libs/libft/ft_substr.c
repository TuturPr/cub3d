/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 22:03:18 by arthur            #+#    #+#             */
/*   Updated: 2024/10/22 02:12:35 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s || (int)start >= ft_strlen((char *)s))
		return (ft_strdup(""));
	str = malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!s)
		return (NULL);
	while (i < len && s[start + i] != '\0')
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/* int main()
{
    char str[50] = "world Hello eu";
    
    printf("%s", ft_substr(str, 6, 5));
} */