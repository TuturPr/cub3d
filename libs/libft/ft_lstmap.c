/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:27:11 by arthur            #+#    #+#             */
/*   Updated: 2025/03/10 16:16:37 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*init;
	t_list	*new;
	void	*new_content;

	if (!f || !del || !lst)
		return (NULL);
	init = NULL;
	while (lst)
	{
		new_content = (*f)(lst->content);
		new = ft_lstnew(new_content);
		if (!new)
		{
			(*del)(new_content);
			ft_lstclear(&init, del);
		}
		ft_lstadd_back(&init, new);
		lst = lst->next;
	}
	return (init);
}
