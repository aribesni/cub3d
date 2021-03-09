/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wildcard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:52:58 by aribesni          #+#    #+#             */
/*   Updated: 2020/05/01 11:57:11 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_wildcard_2(int j, int k, const char *str, t_list *elem)
{
	elem->wid = (elem->tmp < 0) ? -elem->tmp : elem->tmp;
	elem->space = elem->wid - elem->size;
	if (elem->prec > elem->size
		|| (elem->u_integer == 0 && elem->prec >= 0 && str[k] == '.'))
		elem->space = elem->wid - elem->prec;
	while (elem->space-- > 0 && elem->wid > elem->prec && elem->tmp > 0)
	{
		if (str[j] != '0')
			ft_putchar(' ');
	}
}

void			ft_wildcard(int j, int k, const char *str, t_list *elem)
{
	if (elem->conv == 'i' || elem->conv == 'd')
	{
		elem->wid = (elem->tmp < 0) ? -elem->tmp : elem->tmp;
		if (elem->neg < 0 && elem->prec >= elem->size)
		{
			if (elem->prec > elem->wid && elem->wid < elem->size
				&& elem->tmp >= 0 && elem->prec > elem->size)
				elem->ret++;
		}
		if (elem->prec >= elem->size && elem->neg < 0)
			elem->space = elem->wid - elem->prec - 1;
		else if (elem->prec > elem->size)
			elem->space = elem->wid - elem->prec;
		else
			elem->space = elem->wid - elem->size;
		while (elem->space-- > 0 && elem->wid > elem->prec
			&& elem->tmp > 0 && str[j] != '0')
			ft_putchar(' ');
	}
	else if (elem->conv == 'u' || elem->conv == 'x' || elem->conv == 'X')
		ft_wildcard_2(j, k, str, elem);
}
