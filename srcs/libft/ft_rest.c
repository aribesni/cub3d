/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 20:35:57 by aribesni          #+#    #+#             */
/*   Updated: 2020/05/04 22:55:11 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_rest_5(int j, int ***z, const char *str, t_list *elem)
{
	int			i;

	i = j - (elem->prec - elem->size);
	if (str[***z - 1] != '-')
	{
		i = (elem->size == elem->prec && elem->neg < 0) ?
		elem->wid - elem->size - 1 : elem->wid - elem->prec;
		while ((i--) > 0 && str[***z] != '*' && elem->tmp >= 0)
			ft_putchar(' ');
	}
	i = elem->prec - elem->size;
	if (elem->neg < 0)
	{
		ft_putchar('-');
		i = elem->prec - (elem->size - 1);
		elem->ret += ((elem->wid > elem->prec && elem->wid > elem->size &&
		elem->prec <= elem->size) || (elem->wid < elem->prec && elem->wid <
		elem->size && elem->prec < elem->size) || (elem->wid < elem->prec &&
		elem->wid < elem->size && elem->size < elem->prec && str[***z] == '*'
		&& str[***z - 1] != '-')) ? 0 : 1;
	}
	while (i-- > 0)
		ft_putchar('0');
	elem->integer *= (elem->neg < 0) ? -1 : 1;
}

static void		ft_rest_4(int j, int l, const char *str, t_list *elem)
{
	if (elem->prec == 0 && str[l] == '.' && elem->u_integer == 0
		&& elem->conv != 'i' && elem->conv != 'd')
		j = elem->wid;
	while (j-- > 0)
		ft_putchar(' ');
}

static void		ft_rest_3(int k, const char *str, t_list *elem)
{
	while (str[k] == '0')
		k++;
	if (str[k] == '*')
		elem->wid = (elem->tmp < 0) ? -elem->tmp : elem->tmp;
}

static void		ft_rest_2(int *j, int ***z, const char *str, t_list *elem)
{
	int			l;
	char		*s1;

	l = (str[*j] == '*') ? *j + 1 : *j;
	if (str[l - 1] != '*')
	{
		s1 = ft_substr(str, ***z, (*j - ***z));
		elem->wid = ft_atoi(s1);
		*j = elem->wid - elem->size;
		free(s1);
	}
	if (str[***z] == '*' || str[***z - 1] == '*')
	{
		elem->wid = (elem->tmp < 0) ? -elem->tmp : elem->tmp;
		*j = elem->tmp - elem->size;
	}
	if (elem->integer < 0 && elem->prec > elem->size
		&& elem->prec < elem->wid && (elem->conv == 'i'
		|| elem->conv == 'd'))
		elem->wid--;
}

void			ft_rest(int j, int **z, const char *str, t_list *elem)
{
	int			k;
	int			l;

	k = j;
	while (str[j] >= '0' && str[j] <= '9' && str[j])
		j++;
	l = (str[j] == '*') ? j + 1 : j;
	ft_rest_2(&j, &z, str, elem);
	if (str[k] == '0' && str[**z - 1] != '-' && str[k + 1] != '.')
	{
		if (str[**z] != '*' && str[**z - 1] != '*')
			ft_rest_3(k, str, elem);
		ft_zero(l, str, elem);
	}
	else if (elem->prec >= elem->size && str[l] == '.')
		ft_rest_5(j, &z, str, elem);
	else if (elem->prec <= elem->size && str[**z - 1] != '-'
		&& str[l - 1] != '*')
		ft_rest_4(j, l, str, elem);
}
