/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:41:16 by aribesni          #+#    #+#             */
/*   Updated: 2019/10/25 14:41:18 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *new_lst)
{
	int		count;

	count = 0;
	while (new_lst)
	{
		new_lst = new_lst->next;
		count++;
	}
	return (count);
}
