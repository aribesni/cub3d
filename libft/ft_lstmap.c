/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:40:28 by aribesni          #+#    #+#             */
/*   Updated: 2019/10/25 14:40:29 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*dest;
	t_list	*new_list;

	dest = NULL;
	new_list = NULL;
	while (lst)
	{
		if (!(new_list = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&dest, del);
			return (NULL);
		}
		ft_lstadd_back(&dest, new_list);
		lst = lst->next;
	}
	return (dest);
}
