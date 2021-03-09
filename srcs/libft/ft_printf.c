/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 20:35:22 by aribesni          #+#    #+#             */
/*   Updated: 2020/04/30 14:55:08 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_count(char c, t_list *elem)
{
	ft_putchar(c);
	elem->ret++;
}

static void		ft_check_str_2(int *i, const char *str, t_list *elem)
{
	int		z;

	z = *i;
	ft_flags(str, &i);
	if (str[*i + 1] == 'c' || str[*i + 1] == '%')
		ft_print_c(elem, str, &z, str[*i + 1]);
	else if (str[*i + 1] == 's')
		ft_print_s(elem, str, &z, str[*i + 1]);
	else if (str[*i + 1] == 'i' || str[*i + 1] == 'd' || str[*i + 1] == 'u'
			|| str[*i + 1] == 'x' || str[*i + 1] == 'X')
		ft_print_i_u(elem, str, &z, str[*i + 1]);
	else if (str[*i + 1] == 'p')
		ft_print_p(elem, str, &z, str[*i + 1]);
	else
		ft_count(str[*i], elem);
	*i += 1;
}

static void		ft_check_str(const char *str, t_list *elem)
{
	int			i;

	i = -1;
	while (str[++i])
	{
		ft_reset(elem);
		if (str[i] == '%')
			ft_check_str_2(&i, str, elem);
		else
			ft_count(str[i], elem);
	}
}

int				ft_printf(const char *str, ...)
{
	t_list	elem;

	elem.ret = 0;
	va_start(elem.pointer, str);
	ft_check_str(str, &elem);
	va_end(elem.pointer);
	return (elem.ret);
}
