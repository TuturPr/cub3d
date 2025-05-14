/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:34:56 by aperceva          #+#    #+#             */
/*   Updated: 2024/10/21 16:12:09 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(unsigned char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/*#include <ctype.h>
int main()
{
	
	int i;
 
        i = -1;
        while (i < 530)
        {
                if (ft_isalpha(i) != isalpha(i))
                        printf("%d", isalpha(i));
                i++;
        }
        printf("%s", "SUCCESS");
 
}
*/