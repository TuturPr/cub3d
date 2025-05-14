/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:12:23 by arthur            #+#    #+#             */
/*   Updated: 2024/10/22 02:05:13 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_sep(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (!find_sep(*s, c) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (find_sep(*s, c))
			in_word = 0;
		s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char			**ptr;
	unsigned int	start;
	int				i_tab;
	size_t			i;

	if (!s)
		return (NULL);
	ptr = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	start = 0;
	i_tab = 0;
	while (s[i])
	{
		while (s[i] && find_sep(s[i], c))
			i++;
		start = i;
		while (s[i] && !find_sep(s[i], c))
			i++;
		if (start < i)
			ptr[i_tab++] = ft_substr(s, start, i - start);
	}
	ptr[i_tab] = NULL;
	return (ptr);
}
/*
int	main(void)
{
	char	**res;
	int		i;

	res = ft_split("Prison,toilettes,arbre,lunettes,porte,chunckyBOYYYYYY", ',');
	i = 0;
	while (res[i])
	{
		printf("%s\n", res[i]);
		i++;
	}
}
*/