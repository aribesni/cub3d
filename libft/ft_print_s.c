/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 20:35:14 by aribesni          #+#    #+#             */
/*   Updated: 2020/05/01 11:55:04 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_dot_tmp(t_list *elem)
{
	int			i;
	int			j;

	i = elem->prec;
	j = elem->wid;
	if (elem->size == 0)
	{
		while (j--)
			ft_putchar(' ');
	}
	else if (elem->prec > 0)
	{
		while (i--)
			ft_putchar(*elem->string++);
	}
	else if (elem->prec < 0)
		ft_putstr(elem->string);
}

static int		ft_wildcard_s2(int j, int **z, const char *str, t_list *elem)
{
	j++;
	if (str[**z + 1] == '*')
	{
		elem->wid = (elem->tmp < 0) ? -elem->tmp : elem->tmp;
		if (str[j + 1] == '.')
		{
			ft_dot_bis(j, str, elem);
			ft_dot_tmp(elem);
			while (elem->space-- > 0 && elem->size != 0)
				ft_putchar(' ');
			return (1);
		}
		elem->size = ft_strlen(elem->string);
		elem->space = elem->wid - elem->size;
		ft_putstr(elem->string);
		while (elem->space-- > 0)
			ft_putchar(' ');
		elem->ret += (elem->wid < elem->size) ? elem->size : elem->wid;
		return (1);
	}
	return (1);
}

static int		ft_wildcard_s(int j, const char *str, t_list *elem)
{
	elem->wid = (elem->tmp < 0) ? -elem->tmp : elem->tmp;
	if (str[j + 1] == '.')
	{
		ft_dot_bis(j, str, elem);
		if (elem->tmp < 0)
			ft_dot_tmp(elem);
		while (elem->space-- > 0 && elem->size > 0 && elem->prec >= 0)
			ft_putchar(' ');
		if (elem->tmp >= 0)
			ft_dot_tmp(elem);
		return (1);
	}
	elem->space = elem->wid - ft_strlen(elem->string);
	if (elem->tmp < 0)
		ft_putstr(elem->string);
	while (elem->space-- > 0)
		ft_putchar(' ');
	if (elem->tmp >= 0)
		ft_putstr(elem->string);
	elem->ret += (elem->wid < elem->size) ? elem->size : elem->wid;
	return (1);
}

static void		ft_rest_s(int j, int **z, const char *str, t_list *elem)
{
	char		*s1;

	if (str[**z] == '-')
		s1 = ft_substr(str, **z + 1, (j - **z));
	else
		s1 = ft_substr(str, **z, (j - **z));
	elem->wid = ft_atoi(s1);
	elem->size = ft_strlen(elem->string);
	elem->space = elem->wid - elem->size;
	if (str[**z] == '-' && elem->size > 0)
		ft_putstr(elem->string);
	while (elem->space-- > 0)
		ft_putchar(' ');
	if (str[**z] != '-' && elem->size > 0)
		ft_putstr(elem->string);
	elem->ret += (elem->wid < elem->size) ? elem->size : elem->wid;
	free(s1);
}

int				ft_print_s(t_list *elem, const char *str, int *z, char c)
{
	int			j;
	char		*tmp;

	*z += 1;
	j = *z;
	ft_assign(j, &z, str, elem);
	elem->conv = c;
	tmp = va_arg(elem->pointer, char*);
	elem->string = (tmp == NULL) ? "(null)" : tmp;
	elem->size = ft_strlen(elem->string);
	j = (str[*z] == '-') ? *z : j;
	if (str[*z] == '*')
		return (ft_wildcard_s(j, str, elem));
	if (str[*z] == '-' && str[*z + 1] == '*')
		return (ft_wildcard_s2(j, &z, str, elem));
	else if (str[*z] == '-')
		j++;
	while (str[j] >= '0' && str[j] <= '9' && str[j])
		j++;
	if (str[j] == '.')
		return (ft_dot_s(j, &z, str, elem));
	ft_rest_s(j, &z, str, elem);
	ft_reset(elem);
	return (1);
}
