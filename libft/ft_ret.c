/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ret.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:55:39 by aribesni          #+#    #+#             */
/*   Updated: 2020/05/01 11:56:23 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_ret_i(int k, const char *str, t_list *elem)
{
	if (elem->integer == 0 && elem->prec == 0
		&& elem->wid == 0 && str[k] == '.')
		elem->ret += 0;
	else if (elem->integer == 0 && elem->prec == 0
		&& elem->wid == 0 && str[k] != '.')
		elem->ret++;
	else if (elem->prec > elem->wid && elem->prec >= elem->size)
		elem->ret += elem->prec;
	else if (elem->wid > elem->prec && elem->wid >= elem->size)
		elem->ret += elem->wid;
	else if (elem->size > elem->prec && elem->size > elem->wid)
		elem->ret += elem->size;
	else
		elem->ret += elem->wid;
}

static void		ft_ret_u(int k, const char *str, t_list *elem)
{
	if (elem->u_integer == 0 && elem->prec == 0
		&& elem->wid == 0 && str[k] == '.')
		elem->ret += 0;
	else if (elem->u_integer == 0 && elem->prec == 0
		&& elem->wid == 0 && str[k] != '.')
		elem->ret++;
	else if (elem->prec > elem->wid && elem->prec >= elem->size)
		elem->ret += elem->prec;
	else if (elem->wid > elem->prec && elem->wid >= elem->size)
		elem->ret += elem->wid;
	else if (elem->size > elem->prec && elem->size > elem->wid)
		elem->ret += elem->size;
	else
		elem->ret += elem->wid;
}

void			ft_ret(int k, const char *str, t_list *elem)
{
	if (elem->conv == 'i' || elem->conv == 'd')
		ft_ret_i(k, str, elem);
	if (elem->conv == 'u' || elem->conv == 'x' || elem->conv == 'X')
		ft_ret_u(k, str, elem);
}
