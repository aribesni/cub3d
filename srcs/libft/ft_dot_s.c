/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dot_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 20:31:51 by aribesni          #+#    #+#             */
/*   Updated: 2020/05/04 22:47:01 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_minus(t_list *elem)
{
	if (elem->size == 0)
	{
		while (elem->wid--)
			ft_putchar(' ');
	}
	else if (elem->prec > 0)
	{
		while (elem->prec--)
			ft_putchar(*elem->string++);
	}
	else if (elem->prec < 0)
		ft_putstr(elem->string);
}

static void		ft_dot_s3(int ***z, const char *str, t_list *elem)
{
	if (str[***z] == '-')
		ft_minus(elem);
	while (elem->space-- > 0 && elem->size > 0)
		ft_putchar(' ');
	if (str[***z] != '-')
		ft_minus(elem);
}

static void		ft_dot_s2(int i, int ***z, const char *str, t_list *elem)
{
	char		*s1;

	if (str[***z] == '-')
		s1 = ft_substr(str, ***z + 1, (i - ***z));
	else
		s1 = ft_substr(str, ***z, (i - ***z));
	elem->wid = ft_atoi(s1);
	if (elem->prec < 0)
		elem->space = elem->wid - elem->size;
	else
		elem->space = elem->wid - elem->prec;
	if (elem->prec >= 0)
		elem->ret += (elem->prec > elem->wid) ? elem->prec : elem->wid;
	else
		elem->ret += (elem->wid < elem->size) ? elem->size : elem->wid;
	free(s1);
}

int				ft_dot_s(int i, int **z, const char *str, t_list *elem)
{
	int			j;
	char		*s1;

	i++;
	j = i;
	while (str[j] >= '0' && str[j] <= '9' && str[j])
		j++;
	if (str[i] == '*')
		elem->prec = elem->tmp2;
	else
	{
		s1 = ft_substr(str, i, (j - i));
		if (ft_atoi(s1) > ft_strlen(elem->string))
			elem->prec = ft_strlen(elem->string);
		else
			elem->prec = ft_atoi(s1);
		free(s1);
	}
	i++;
	if (elem->prec > elem->size)
		elem->prec = elem->size;
	ft_dot_s2(i, &z, str, elem);
	ft_dot_s3(&z, str, elem);
	return (1);
}
