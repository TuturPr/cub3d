/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 23:01:12 by arthur            #+#    #+#             */
/*   Updated: 2024/10/22 01:57:00 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
		{
			return (1);
		}
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*start;
	const char	*end;
	char		*trimmed_str;
	size_t		len;

	if (!s1 || !set)
		return (NULL);
	start = s1;
	while (is_in_set(*start, set))
		start++;
	end = s1 + ft_strlen((char *)s1) - 1;
	while (end > start && is_in_set(*end, set))
		end--;
	len = end - start + 1;
	trimmed_str = malloc(len + 1);
	if (!trimmed_str)
		return (NULL);
	ft_strlcpy(trimmed_str, start, len + 1);
	return (trimmed_str);
}
/* int main()
{
    char str[50] = "abcdefworld Helloabcdef";
	char set[50] = "abcdef";
    
    printf("%s", ft_strtrim(str, set));
}  */