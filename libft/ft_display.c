/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 20:31:51 by aribesni          #+#    #+#             */
/*   Updated: 2020/04/30 19:46:50 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_display_x(int k, const char *str, t_list *elem)
{
	if (elem->u_integer == 0 && str[k] != '.')
		ft_putnbr(0);
	else if (elem->u_integer == 0 && str[k] == '.' && elem->prec != 0)
		ft_putnbr(0);
	else if (elem->u_integer != 0 && str[k] != '.')
		ft_putnbr_base_u(elem->u_integer, "0123456789abcdef");
	else if (elem->u_integer != 0 && str[k] == '.' && elem->prec != 0)
		ft_putnbr_base_u(elem->u_integer, "0123456789abcdef");
	else if (elem->u_integer != 0 && str[k] == '.' && elem->wid == 0
		&& elem->prec == 0)
		ft_putnbr_base_u(elem->u_integer, "0123456789abcdef");
	else if (elem->u_integer != 0 && str[k] == '.' && elem->wid != 0
		&& elem->prec == 0)
		ft_putnbr_base_u(elem->u_integer, "0123456789abcdef");
}

static void		ft_display_cap_x(int k, const char *str, t_list *elem)
{
	if (elem->u_integer == 0 && str[k] != '.')
		ft_putnbr(0);
	else if (elem->u_integer == 0 && str[k] == '.' && elem->prec != 0)
		ft_putnbr(0);
	else if (elem->u_integer != 0 && str[k] != '.')
		ft_putnbr_base_u(elem->u_integer, "0123456789ABCDEF");
	else if (elem->u_integer != 0 && str[k] == '.' && elem->prec != 0)
		ft_putnbr_base_u(elem->u_integer, "0123456789ABCDEF");
	else if (elem->u_integer != 0 && str[k] == '.' && elem->wid == 0
		&& elem->prec == 0)
		ft_putnbr_base_u(elem->u_integer, "0123456789ABCDEF");
	else if (elem->u_integer != 0 && str[k] == '.' && elem->wid != 0
		&& elem->prec == 0)
		ft_putnbr_base_u(elem->u_integer, "0123456789ABCDEF");
}

static void		ft_display_u(int k, const char *str, t_list *elem)
{
	if (elem->u_integer == 0 && str[k] != '.')
		ft_putnbr(0);
	else if (elem->u_integer == 0 && str[k] == '.' && elem->prec != 0)
		ft_putnbr(0);
	else if (elem->u_integer != 0 && str[k] != '.')
		ft_putnbr(elem->u_integer);
	else if (elem->u_integer != 0 && str[k] == '.' && elem->prec != 0)
		ft_putnbr(elem->u_integer);
	else if (elem->u_integer != 0 && str[k] == '.' && elem->wid == 0
		&& elem->prec == 0)
		ft_putnbr(elem->u_integer);
	else if (elem->u_integer != 0 && str[k] == '.' && elem->wid != 0
		&& elem->prec == 0)
		ft_putnbr(elem->u_integer);
}

static void		ft_display_i(int k, const char *str, t_list *elem)
{
	if (elem->integer == 0 && str[k] != '.')
		ft_putnbr(0);
	else if (elem->integer == 0 && str[k] == '.' && elem->prec != 0)
		ft_putnbr(0);
	else if (elem->integer != 0 && str[k] != '.')
		ft_putnbr(elem->integer);
	else if (elem->integer != 0 && str[k] == '.' && elem->prec != 0)
		ft_putnbr(elem->integer);
	else if (elem->integer != 0 && str[k] == '.' && elem->wid == 0
		&& elem->prec == 0)
		ft_putnbr(elem->integer);
	else if (elem->integer != 0 && str[k] == '.' && elem->wid != 0
		&& elem->prec == 0)
		ft_putnbr(elem->integer);
	else if (elem->integer == 0 && elem->prec == 0 && elem->wid > 0
		&& str[k] == '.')
		ft_putchar(' ');
}

void			ft_display(int k, const char *str, t_list *elem)
{
	if (elem->conv == 'i' || elem->conv == 'd')
		ft_display_i(k, str, elem);
	else if (elem->conv == 'u')
		ft_display_u(k, str, elem);
	else if (elem->conv == 'x')
		ft_display_x(k, str, elem);
	else if (elem->conv == 'X')
		ft_display_cap_x(k, str, elem);
}
