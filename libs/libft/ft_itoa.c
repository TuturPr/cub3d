/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:47:22 by arthur            #+#    #+#             */
/*   Updated: 2024/10/19 11:12:11 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nmb_len(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		len;
	long	num;

	num = n;
	len = nmb_len(num);
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	if (num < 0)
	{
		ptr[0] = '-';
		num = -num;
	}
	while (len > 0 && num != 0)
	{
		ptr[--len] = (num % 10) + '0';
		num = num / 10;
	}
	if (n == 0)
		ptr[0] = '0';
	return (ptr);
}
/*
int	main(void)
{
    int numbers[] = {123, -123, 0, 2147483647, -2147483648};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    char *str;
    int i;

    // Boucle pour tester différents nombres
    for (i = 0; i < size; i++)
    {
        str = ft_itoa(numbers[i]);
        if (str)
        {
            printf("Integer: %d -> String: %s\n", numbers[i], str);
            free(str);  // Ne pas oublier de libérer la mémoire allouée
        }
        else
        {
            printf("Memory allocation failed for integer: %d\n", numbers[i]);
        }
    }

    return (0);
}
*/