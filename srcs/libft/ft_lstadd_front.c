/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:37:35 by aribesni          #+#    #+#             */
/*   Updated: 2019/10/25 14:51:10 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new_lst)
{
	t_list	*temp;

	if (!alst)
		return ;
	temp = *alst;
	*alst = new_lst;
	new_lst->next = temp;
}
