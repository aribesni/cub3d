/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_i_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 20:34:57 by aribesni          #+#    #+#             */
/*   Updated: 2020/05/04 22:59:41 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_neg_2(t_list *elem)
{
	int		i;

	if (elem->neg < 0
		&& (elem->conv == 'i' || elem->conv == 'd'))
		elem->wid -= (elem->tmp < 0) ? 1 : 0;
	i = elem->wid - elem->prec;
	while (i-- > 0)
		ft_putchar(' ');
}

static int		ft_neg(int k, const char *str, t_list *elem)
{
	int			i;

	ft_ret(k, str, elem);
	ft_display(k, str, elem);
	elem->wid = (elem->tmp < 0) ? -elem->tmp : elem->wid;
	if (elem->prec && elem->prec > elem->wid
		&& elem->wid > elem->size && elem->wid > 0)
		return (1);
	if (elem->prec && elem->prec < elem->wid
		&& elem->wid > elem->size && elem->prec > elem->size)
		ft_neg_2(elem);
	else if (elem->prec != elem->wid)
	{
		if (elem->prec == 0 && str[k] == '.' && elem->u_integer == 0
			&& elem->conv != 'i' && elem->conv != 'd')
			i = elem->wid;
		else
			i = elem->wid - elem->size;
		i = (elem->prec == elem->size && elem->size > 1 && elem->conv != 'x' &&
			elem->conv != 'X' && elem->neg < 0 && (elem->conv == 'd' ||
			elem->conv == 'i')) ? elem->wid - (elem->prec + 1) : i;
		while (i-- > 0)
			ft_putchar(' ');
	}
	return (1);
}

static void		ft_dot(int k, const char *str, t_list *elem)
{
	int			l;
	char		*s1;

	k++;
	l = k;
	while (str[l] >= '0' && str[l] <= '9' && str[l])
		l++;
	s1 = ft_substr(str, k, (l - k));
	elem->prec = (str[k] == '*') ? elem->tmp2 : ft_atoi(s1);
	free(s1);
}

static void		ft_browse(int *k, const char *str, t_list *elem)
{
	while (str[*k] != '.' && (str[*k] != '\0' && str[*k] != '%'))
		*k += 1;
	if (str[*k] == '.')
		ft_dot(*k, str, elem);
}

int				ft_print_i_u(t_list *elem, const char *str, int *z, char c)
{
	int			j;
	int			k;

	*z += 1;
	j = *z;
	k = j;
	elem->conv = c;
	ft_assign(j, &z, str, elem);
	ft_browse(&k, str, elem);
	if (str[*z] == '*')
		ft_wildcard(j, k, str, elem);
	j = (str[*z] == '-') ? *z : j;
	if (str[j] == '-' || elem->tmp < 0)
	{
		j++;
		*z += 1;
		ft_rest(j, &z, str, elem);
		return (ft_neg(k, str, elem));
	}
	ft_rest(j, &z, str, elem);
	ft_ret(k, str, elem);
	if (str[*z] != '-')
		ft_display(k, str, elem);
	return (1);
}
